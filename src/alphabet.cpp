
/*******************************************************************/
/*                                                                 */
/*  MODULE   alphabet                                              */
/*  PROGRAM  SFST                                                  */
/*  AUTHOR   Helmut Schmid, IMS, University of Stuttgart           */
/*                                                                 */
/*  PURPOSE  basic FST functions                                   */
/*                                                                 */
/*******************************************************************/

#include <climits>
#include <cstring>
#include <regex>

#include "alphabet.h"
#include "utf8.h"

#include <map>
using std::map;

namespace SFST {

using std::ostream;
using std::vector;

const int BUFFER_SIZE = 100000;

char EpsilonString[] = "<>";

/*******************************************************************/
/*                                                                 */
/*  Alphabet::add                                                  */
/*                                                                 */
/*******************************************************************/

void Alphabet::add(std::string symbol, Character c)

{
  if (sm.find(symbol) != sm.end()) {
    std::cerr << "Duplicate insertion " << symbol << "\n";
  } else {
    cm[c] = symbol;
    sm[symbol] = c;
  }
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::Alphabet                                             */
/*                                                                 */
/*******************************************************************/

Alphabet::Alphabet()

{
  utf8 = false;
  add(EpsilonString, Label::epsilon);
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::clear                                                */
/*                                                                 */
/*******************************************************************/

void Alphabet::clear()

{
  ls.clear();
  sm.clear();
  cm.clear();
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::print                                                */
/*                                                                 */
/*******************************************************************/

void Alphabet::print(void)

{
  for (LabelSet::const_iterator it = begin(); it != end(); it++) {
    Label l = *it;
    std::cerr << write_label(l) << "\n";
  }
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::new_marker                                           */
/*                                                                 */
/*******************************************************************/

Character Alphabet::new_marker()

{
  // find some unused character code
  for (Character i = 1; i != 0; i++)
    if (cm.find(i) == cm.end()) {
      // create a unique identifier string
      char symbol[100];
      sprintf(symbol, ">%ld<", (long)i);
      add(symbol, i);
      return i;
    }

  throw "Error: too many symbols in transducer definition";
}

/*******************************************************************/
/*                                                                 */
/*  is_marker_symbol                                               */
/*                                                                 */
/*******************************************************************/

static bool is_marker_symbol(std::string s)

{
  // recognize strings matching the expression ">[0-9]+<"
  return std::regex_match(s, std::regex(">[0-9]+<"));
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::delete_markers                                       */
/*                                                                 */
/*******************************************************************/

void Alphabet::delete_markers()

{
  vector<std::string> sym;
  vector<Character> code;
  vector<Label> label;

  for (CharMap::const_iterator it = cm.begin(); it != cm.end(); it++) {
    Character c = it->first;
    std::string s = it->second;
    if (!is_marker_symbol(s)) {
      sym.push_back(s);
      code.push_back(c);
    }
  }

  for (LabelSet::const_iterator it = begin(); it != end(); it++) {
    Label l = *it;
    if (!is_marker_symbol(code2symbol(l.upper_char())) &&
        !is_marker_symbol(code2symbol(l.lower_char())))
      label.push_back(l);
  }

  clear();

  for (size_t i = 0; i < sym.size(); i++) {
    add_symbol(sym[i], code[i]);
  }
  for (size_t i = 0; i < label.size(); i++) {
    insert(label[i]);
  }
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::add_symbol                                           */
/*                                                                 */
/*******************************************************************/

Character Alphabet::add_symbol(std::string symbol)

{
  if (sm.find(symbol) != sm.end()) {
    return sm[symbol];
  }

  // assign the symbol to some unused character
  for (Character i = 1; i != 0; i++)
    if (cm.find(i) == cm.end()) {
      add(symbol, i);
      return i;
    }

  throw "Error: too many symbols in transducer definition";
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::add_symbol                                           */
/*                                                                 */
/*******************************************************************/

void Alphabet::add_symbol(std::string symbol, Character c)

{
  // check whether the symbol was previously defined
  int sc = symbol2code(symbol);
  if (sc != EOF) {
    if ((Character)sc == c)
      return;

    if (symbol.length() < 60) {
      static char message[100];
      sprintf(message,
              "Error: reinserting symbol '%s' in alphabet with incompatible "
              "character value %u %u",
              symbol.c_str(), (unsigned)sc, (unsigned)c);
      throw message;
    } else
      throw "reinserting symbol in alphabet with incompatible character value";
  }

  // check whether the character is already in use
  std::string s = code2symbol(c);
  if (s == "NULL") {
    add(symbol, c);
  } else {
    if (s.compare(symbol) != 0) {
      static char message[100];
      if (symbol.length() < 70)
        sprintf(message,
                "Error: defining symbol %s as character %d (previously defined "
                "as %s)",
                symbol.c_str(), (unsigned)c, s.c_str());
      else
        sprintf(message, "Error: defining a (very long) symbol with previously "
                         "used character");
      throw message;
    }
  }
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::write_char                                           */
/*                                                                 */
/*******************************************************************/

std::string Alphabet::write_char(Character c, bool with_brackets) const {
  std::string s = code2symbol(c);
  // quote colons
  std::string buffer = "";
  if (s == ":" || s == "\\") {
    buffer += '\\';
    buffer += s;
  } else if (s != "NULL") {
    buffer += s;
  } else {
    unsigned int uc = c;
    if (uc >= 32 && uc < 256)
      buffer += (char)c;
    else {
      buffer += uc;
    }
  }
  return buffer;
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::write_label                                          */
/*                                                                 */
/*******************************************************************/

std::string Alphabet::write_label(Label l, bool with_brackets) const {
  Character lc = l.lower_char();
  Character uc = l.upper_char();
  std::string buffer = "";
  buffer += write_char(lc, with_brackets);
  if (lc != uc) {
    buffer += ':';
    buffer += write_char(uc, with_brackets);
  }

  return buffer;
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::insert_symbols                                       */
/*                                                                 */
/*******************************************************************/

void Alphabet::insert_symbols(const Alphabet &a)

{
  for (CharMap::const_iterator it = a.cm.begin(); it != a.cm.end(); it++)
    add_symbol(it->second, it->first);
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::complement                                           */
/*                                                                 */
/*******************************************************************/

void Alphabet::complement(vector<Character> &sym)

{
  vector<Character> result;
  for (CharMap::const_iterator it = cm.begin(); it != cm.end(); it++) {
    Character c = it->first;
    if (c != Label::epsilon) {
      size_t i;
      for (i = 0; i < sym.size(); i++)
        if (sym[i] == c)
          break;
      if (i == sym.size())
        result.push_back(c);
    }
  }
  sym.swap(result);
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::copy                                                 */
/*                                                                 */
/*******************************************************************/

void Alphabet::copy(const Alphabet &a, Level level)

{
  utf8 = a.utf8;
  sm.reserve(a.sm.size());
  cm.reserve(a.sm.size());
  insert_symbols(a);
  for (LabelSet::const_iterator it = a.begin(); it != a.end(); it++) {
    Label l = *it;
    if (level == lower)
      ls.insert(Label(l.lower_char()));
    else if (level == upper)
      ls.insert(Label(l.upper_char()));
    else
      ls.insert(l);
  }
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::compose                                              */
/*                                                                 */
/*******************************************************************/

void Alphabet::compose(const Alphabet &la, const Alphabet &ua)

{
  // insert the symbols
  insert_symbols(la);
  insert_symbols(ua);
  utf8 = la.utf8;

  map<Character, set<Character>> cs;

  // create a table for a quick lookup of the target characters
  for (iterator it = ua.begin(); it != ua.end(); it++) {
    Character lc = it->lower_char();
    if (lc == Label::epsilon)
      insert(*it);
    else
      cs[lc].insert(it->upper_char());
  }

  for (iterator it = la.begin(); it != la.end(); it++) {
    Character uc = it->upper_char();
    if (uc == Label::epsilon)
      insert(*it);
    else {
      if (cs.find(uc) != cs.end()) {
        set<Character> s = cs[uc];
        Character lc = it->lower_char();
        for (set<Character>::iterator it = s.begin(); it != s.end(); it++)
          insert(Label(lc, *it));
      }
    }
  }
}

/*******************************************************************/
/*                                                                 */
/*  operator<<(Alphabet)                                           */
/*                                                                 */
/*******************************************************************/

ostream &operator<<(ostream &s, const Alphabet &a)

{
  for (Alphabet::CharMap::const_iterator it = a.cm.begin(); it != a.cm.end();
       it++)
    s << it->first << " -> " << it->second << "\n";
  for (Alphabet::iterator it = a.begin(); it != a.end(); it++)
    s << a.write_label(*it) << " ";
  s << "\n";
  return s;
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::next_mcsym                                           */
/*                                                                 */
/*  recognizes multi-character symbols which are enclosed with     */
/*  angle brackets <...>. If the argument flag insert is false,    */
/*  the multi-character symbol must already be in the lexicon in   */
/*  order to be recognized.                                        */
/*                                                                 */
/*******************************************************************/

int Alphabet::next_mcsym(char *&str, bool insert) {

  char *start = str;

  if (*start == '<')
    // symbol might start here
    for (char *end = start + 1; *end; end++)
      if (*end == '>') {
        // matching pair of angle brackets found
        // mark the end of the substring with \0
        char lastc = *(++end);
        *end = 0;

        int c;
        if (insert)
          c = add_symbol(start);
        else
          c = symbol2code(start);
        // restore the original string
        *end = lastc;

        if (c != EOF) {
          // symbol found
          // return its code
          str = end;
          return (Character)c;
        } else
          // not a complex character
          break;
      }
  return EOF;
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::next_code                                            */
/*                                                                 */
/*******************************************************************/

int Alphabet::next_code(char *&str, bool extended, bool insert) {

  if (*str == 0)
    return EOF; // finished

  int c = next_mcsym(str, insert);
  if (c != EOF)
    return c;

  if (extended && *str == '\\')
    str++; // remove quotation

  if (utf8) {
    unsigned int c = utf8toint(&str);
    if (c == 0) {
      fprintf(stderr, "Error in UTF-8 encoding at: <%s>\n", str);
      return EOF; // error encountered in utf8 character
    }
    return (int)add_symbol(int2utf8(c));
  } else {
    char buffer[2];
    buffer[0] = *str;
    buffer[1] = 0;
    str++;
    return (int)add_symbol(buffer);
  }
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::next_label                                           */
/*                                                                 */
/*******************************************************************/

Label Alphabet::next_label(char *&string, bool extended) {
  // read first character
  int c = next_code(string, extended);
  if (c == EOF)
    return Label(); // end of string reached

  Character lc = (Character)c;
  if (!extended || *string != ':') { // single character?
    if (lc == Label::epsilon)
      return next_label(string, extended); // ignore epsilon
    return Label(lc);
  }

  // read second character
  string++; // jump over ':'
  c = next_code(string, extended);
  if (c == EOF) {
    static char buffer[1000];
    sprintf(buffer, "Error: incomplete symbol in input file: %s", string);
    throw buffer;
  }

  Label l(lc, (Character)c);
  if (l.is_epsilon())
    return next_label(string, extended); // ignore epsilon transitions
  return l;
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::string2symseq                                        */
/*                                                                 */
/*******************************************************************/

void Alphabet::string2symseq(std::string s, vector<Character> &ch)

{
  int c;

  char *cstr = new char[s.length() + 1];
  std::strcpy(cstr, s.c_str());

  while ((c = next_code(cstr, false, false)) != EOF)
    ch.push_back((Character)c);
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::string2labelseq                                      */
/*                                                                 */
/*******************************************************************/

void Alphabet::string2labelseq(std::string s, vector<Label> &labels)

{
  Label l;
  char *cstr = new char[s.length() + 1];
  std::strcpy(cstr, s.c_str());

  while ((l = next_label(cstr)) != Label::epsilon)
    labels.push_back(l);
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::store                                                */
/*                                                                 */
/*******************************************************************/

void Alphabet::store(FILE *file) const

{
  char c = (utf8) ? (char)1 : (char)0;
  fputc(c, file);

  // write the symbol mapping
  Character n = (Character)cm.size();
  fwrite(&n, sizeof(n), 1, file);
  for (CharMap::const_iterator it = cm.begin(); it != cm.end(); it++) {
    Character c = it->first;
    std::string s = it->second;
    fwrite(&c, sizeof(c), 1, file);
    const char *cs = s.c_str();
    fwrite(cs, sizeof(char), strlen(cs) + 1, file);
  }

  // write the character pairs
  n = (Character)size();
  fwrite(&n, sizeof(n), 1, file);
  for (LabelSet::const_iterator p = ls.begin(); p != ls.end(); p++) {
    Character c = p->lower_char();
    fwrite(&c, sizeof(c), 1, file);
    c = p->upper_char();
    fwrite(&c, sizeof(c), 1, file);
  }

  if (ferror(file))
    throw "Error encountered while writing alphabet to file\n";
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::read                                                 */
/*                                                                 */
/*******************************************************************/

void Alphabet::read(FILE *file)

{
  utf8 = (fgetc(file) != 0);

  // read the symbol mapping
  Character n = 0;
  read_num(&n, sizeof(n), file);
  for (unsigned i = 0; i < n; i++) {
    char buffer[BUFFER_SIZE];
    Character c;
    read_num(&c, sizeof(c), file);
    if (!read_string(buffer, BUFFER_SIZE, file) || feof(file) || ferror(file))
      throw "Error1 occurred while reading alphabet!\n";
    add_symbol(buffer, c);
  }

  // read the character pairs
  read_num(&n, sizeof(n), file);
  if (ferror(file))
    throw "Error2 occurred while reading alphabet!\n";
  for (unsigned i = 0; i < n; i++) {
    Character lc, uc;
    read_num(&lc, sizeof(lc), file);
    read_num(&uc, sizeof(uc), file);
    insert(Label(lc, uc));
  }
  if (ferror(file))
    throw "Error3 occurred while reading alphabet!\n";
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::compute_score                                        */
/*                                                                 */
/*******************************************************************/

int Alphabet::compute_score(Analysis &ana)

{
  // check whether the morpheme boundaries are explicitly marked
  // with <X> tags
  int score = 0;
  for (size_t i = 0; i < ana.size(); i++) {

    // get next symbol
    std::string sym = write_char(ana[i].lower_char());

    if (sym == "<X>")
      score--;
  }
  if (score < 0)
    return score;

  // No explicit morpheme boundary markers have been found.
  // Count the number of part-of-speech and PREF tags.
  for (size_t i = 0; i < ana.size(); i++) {

    // get next symbol
    std::string sym = write_char(ana[i].lower_char());

    // Is it not a multi-character symbol
    if (sym[0] != '<' || sym[1] == 0)
      continue;

    // Is it a POS tag starting with "+" like <+NN>?
    // Is it a potential POS tag (i.e. all uppercase)?
    if (std::regex_match(sym, std::regex("<+[A-Z]+>")))
      return score;

    // Is it a potential POS tag (i.e. all uppercase)?
    if (std::regex_match(sym, std::regex("<[A-Z]+>")))
      continue;

    // uppercase symbol found
    if (sym == "<SUFF>" || sym == "<OLDORTH>" || sym == "<NEWORTH>")
      continue; // not what we are looking for

    // disprefer nouns with prefixes
    if (sym == "<PREF>")
      score -= 2;

    if (sym == "<V>" || sym == "<ADJ>") {
      bool is_verb = sym == "<V>";
      // get the next non-empty symbol
      Character c = Label::epsilon;
      size_t k;
      for (k = i + 1; k < ana.size(); k++)
        if ((c = ana[k].lower_char()) != Label::epsilon)
          break;
      // Is it a participle
      if (c != Label::epsilon) {
        sym = write_char(c);
        if ((sym == "<OLDORTH>") || (sym == "<NEWORTH>") || (sym == "<SUFF>")) {
          for (k++; k < ana.size(); k++)
            if ((c = ana[k].lower_char()) != Label::epsilon)
              break;
          if (c != Label::epsilon)
            sym = write_char(c);
        }
        if (is_verb && ((sym == "<PPres>") || (sym == "<PPast>")))
          continue; // don't consider participles as complex
        if (!is_verb && ((sym == "<Sup>") || (sym == "<Comp>")))
          continue;
      }
    }
    score--;
  }
  return score;
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::disambiguate                                         */
/*                                                                 */
/*******************************************************************/

void Alphabet::disambiguate(vector<Analysis> &analyses)

{
  // compute the scores
  int bestscore = INT_MIN;
  vector<int> score;

  for (size_t i = 0; i < analyses.size(); i++) {
    score.push_back(compute_score(analyses[i]));
    if (bestscore < score[i])
      bestscore = score[i];
  }

  // delete suboptimal analyses
  size_t k = 0;
  for (size_t i = 0; i < analyses.size(); i++)
    if (score[i] == bestscore)
      analyses[k++] = analyses[i];
  analyses.reserve(k);
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::print_analysis                                       */
/*                                                                 */
/*******************************************************************/

std::string Alphabet::print_analysis(Analysis &ana, bool both_layers)

{
  std::string result;

  // for each transition
  for (size_t i = 0; i < ana.size(); i++) {

    // get the transition label
    Label l = ana[i];
    std::string s;

    // either print the analysis symbol or the whole label
    if (both_layers)
      s = write_label(l);
    else if (l.lower_char() != Label::epsilon)
      s = write_char(l.lower_char());
    else
      continue;

    // copy the characters to the character array
    result += s;
  }

  return result;
}

/*******************************************************************/
/*                                                                 */
/*  Alphabet::operator==                                           */
/*                                                                 */
/*******************************************************************/

bool Alphabet::operator==(const Alphabet &alpha) const

{
  for (SymbolMap::const_iterator it = this->sm.begin(); it != this->sm.end();
       it++) {
    SymbolMap::const_iterator alpha_it = alpha.sm.find(it->first);
    if (alpha_it == alpha.sm.end())
      return false;
    if (alpha_it->second == it->second)
      return false;
  }
  for (SymbolMap::const_iterator alpha_it = alpha.sm.begin();
       alpha_it != alpha.sm.end(); alpha_it++) {
    SymbolMap::const_iterator it = this->sm.find(alpha_it->first);
    if (it == this->sm.end())
      return false;
    if (it->second == alpha_it->second)
      return false;
  }
  return true;
}

} // namespace SFST

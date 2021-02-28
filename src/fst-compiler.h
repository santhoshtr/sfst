/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_FST_COMPILER_H_INCLUDED
# define YY_YY_FST_COMPILER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NEWLINE = 258,                 /* NEWLINE  */
    ALPHA = 259,                   /* ALPHA  */
    COMPOSE = 260,                 /* COMPOSE  */
    PRINT = 261,                   /* PRINT  */
    POS = 262,                     /* POS  */
    INSERT = 263,                  /* INSERT  */
    SWITCH = 264,                  /* SWITCH  */
    ARROW = 265,                   /* ARROW  */
    REPLACE = 266,                 /* REPLACE  */
    SYMBOL = 267,                  /* SYMBOL  */
    VAR = 268,                     /* VAR  */
    SVAR = 269,                    /* SVAR  */
    RVAR = 270,                    /* RVAR  */
    RSVAR = 271,                   /* RSVAR  */
    STRING = 272,                  /* STRING  */
    STRING2 = 273,                 /* STRING2  */
    UTF8CHAR = 274,                /* UTF8CHAR  */
    CHARACTER = 275,               /* CHARACTER  */
    SEQ = 276                      /* SEQ  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "fst-compiler.yy"

  int        number;
  SFST::Twol_Type  type;
  SFST::Repl_Type  rtype;
  char       *name;
  char       *value;
  unsigned char uchar;
  unsigned int  longchar;
  SFST::Character  character;
  SFST::Transducer  *expression;
  SFST::Range      *range;
  SFST::Ranges     *ranges;
  SFST::Contexts   *contexts;

#line 100 "fst-compiler.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_FST_COMPILER_H_INCLUDED  */

% Define the set of valid symbol pairs for the two-level rules.
% The symbol # is used to mark the boundary between the stem and
% the inflectional suffix. It is deleted here.
ALPHABET = [A-Za-z] y:i [e\#]:<> 

% Read the lexical items from a separate file
% each line of which contains a form like "dark"
$WORDS$ = "adj"

% Define a rule which replaces y with i 
% if a morpheme boundary and an e follows
% easy#er -> easier
$R1$ = y<=>i (\#:<> e)

% Define a rule which eliminates e before "#e"
% late#er -> later
$R2$ = e<=><> (\#:<> e)

% Compute the intersection of the two rule transducers
$R$ = $R1$ & $R2$

% Define a transducer for the inflectional endings
$INFL$ = <ADJ>:<> (<pos>:<> | <comp>:{er} | <sup>:{est})

% Concatenate the lexical forms and the inflectional endings and
% put a morpheme boundary in between which is not printed in the analysis
$S$ = $WORDS$ <>:\# $INFL$

% Apply the two level rules
% The result transducer is stored in the output file
$S$ || $R$

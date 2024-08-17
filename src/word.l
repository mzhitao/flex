%option c++ noyywrap yylineno
%{
  #include "Mylexer/Token.h"
%}

%%
[a-zA-zA]+ {return Token::ID;}
\n { return Token::EOL;}
. { return Token::DOT;}
<<EOF>> {return EOF;}
%%

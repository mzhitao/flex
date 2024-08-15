%option c++ noyywrap yylineno
%{
  #include "Mylexer/Token.h"
%}

%%
[a-zA-zA]+ {return Token::WORD;}
\n { return Token::LINE;}
. { return Token::CHAR;}
<<EOF>> {return EOF;}
%%

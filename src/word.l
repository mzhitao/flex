%option outfile="lex.cpp"
%option c++ noyywrap yylineno
%{
  #include "Mylexer/Token.h"
%}

%%
[a-zA-zA]+ { return Token::WORD;}
\n { return Token::LINE;}
. { return Token::OTHER_CHAR;}
%%

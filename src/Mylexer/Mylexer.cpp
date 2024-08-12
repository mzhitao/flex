#include "Mylexer.h"
#include <iostream>

Mylexer::Mylexer() {}

Mylexer::~Mylexer() {}

int Mylexer::yylex()
{
    yyFlexLexer::yylex();
    return 0;
}
#pragma once
#include "FlexLexer.h"
#include "Token.h"

class Mylexer : public yyFlexLexer
{
public:
    Mylexer();
    ~Mylexer();
    virtual int yylex() override;

private:
};

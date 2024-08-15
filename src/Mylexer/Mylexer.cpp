#include "Mylexer.h"
#include "Token.h"
#include <cstring>

Mylexer::Mylexer() {}

Mylexer::~Mylexer() {}

int Mylexer::yylex()
{
    int c = yyFlexLexer::yylex();

    TokenType cc = static_cast<TokenType>(c);
    AddToken(cc, yytext);
    return c;
}
void Mylexer::print() {}
void Mylexer::parse(std::string& text)
{
    setInputString(text);
};
void Mylexer::setInputString(const std::string& str)
{
    inputStream.str(str);
    yyrestart(&inputStream);
}
void Mylexer::AddToken(TokenType type, std::string text)
{
    Token* token = new Token(type, text);
    AddToken(token);
}

void Mylexer::AddToken(Token* token)
{
    tokens.push_back(token);
}
#pragma once
#include "FlexLexer.h"
#include "Token.h"
#include <sstream>
#include <vector>

class Mylexer : public yyFlexLexer
{
public:
    using TokenType   = Token::Id;
    using TokenVector = std::vector<Token*>;

    void parse(std::string& text);
    void setInputString(const std::string& str);

    Mylexer();
    ~Mylexer();
    virtual int yylex() override;
    void        print();

private:
    TokenVector       tokens;
    std::stringstream inputStream;

    void AddToken(TokenType type, std::string text);
    void AddToken(Token* token);
};

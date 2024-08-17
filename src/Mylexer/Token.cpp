
#include "Token.h"
#include <cassert>
#include <string>

const std::map<std::string, double> Token::constMap = {
    {"pi", 3.1415926535897932384626433832795},
    {"e", 2.7182818284590452353602874713527},
    {"phi", 1.6180339887498948482045868343656},
};
int Token::getPriority() const
{
    switch (id_) {
    case Token::ADD:
    case Token::SUB: return 1;
    case Token::MUL:
    case Token::DIV:
    case Token::MOD: return 2;
    case Token::EQ:
    case Token::NEQ:
    case Token::LT:
    case Token::GT:
    case Token::LTE:
    case Token::GTE: return 3;
    case Token::AND:
    case Token::OR: return 4;
    default: return 0;
    }
};
Token::Type Token::getType() const
{
    switch (id_) {
    case Token::ADD:
    case Token::SUB:
    case Token::MUL:
    case Token::DIV:
    case Token::MOD:
    case Token::EQ:
    case Token::NEQ:
    case Token::LT:
    case Token::GT:
    case Token::LTE:
    case Token::GTE:
    case Token::AND:
    case Token::CARET:
    case Token::OR: return Token::Type::BINARY;
    case Token::BANG: return Token::Type::UNARY;
    case Token::NEG:
    case Token::PLUS: return Token::Type::SIGNE;
    case Token::CONST:
    case Token::VAR:
    case Token::NUMBER: return Token::Type::VAL;
    case Token::FUNC: return Token::Type::FUNC;
    default: return Token::Type::UNKNOW;
    }
};
Token::Assoc Token::getAssoc() const
{
    switch (id_) {
    case Token::ADD:
    case Token::SUB:
    case Token::MUL:
    case Token::DIV:
    case Token::MOD:
    case Token::EQ:
    case Token::NEQ:
    case Token::LT:
    case Token::GT:
    case Token::LTE:
    case Token::GTE:
    case Token::AND:
    case Token::OR: return Token::Assoc::LEFT;
    case Token::CARET:
    case Token::BANG:
    case Token::NEG:
    case Token::PLUS: return Token::Assoc::RIGHT;
    default: return Token::Assoc::NONE;
    }
};

//赋值
Token& Token::operator=(Token&& t)
{
    if (this != &t) {
        id_   = t.id_;
        text_ = std::move(t.text_);
    }
    return *this;
}
Token& Token::operator=(const Token& t)
{
    if (this != &t) {
        id_   = t.id_;
        text_ = t.text_;
    }
    return *this;
}

//构造函数
Token::Token(Id id, const std::string text)
    : id_(id)
    , text_(std::move(text)){};

Token::Token(Id id, std::string&& text)
    : id_(id)
    , text_(std::move(text)){};

Token::Token(const Token& token)
    : id_(token.id_)
    , text_(token.text_){};

Token::Token(Token&& token)
    : id_(token.id_)
    , text_(std::move(token.text_)){};
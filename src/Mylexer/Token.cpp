
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
Token::Type Token::getTokenType() const
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
    case Token::OR: return Token::Type::BINARY;
    case Token::CARET:
    case Token::BANG:
    case Token::NEG:
    case Token::PLUS: return Token::Type::UNARY;
    case Token::CONST:
    case Token::VAR:
    case Token::NUMBER: return Token::Type::VAL;
    case Token::FUNC: return Token::Type::FUNC;
    default: return Token::Type::NONE;
    }
};
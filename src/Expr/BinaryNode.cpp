#include "BinaryNode.h"
#include <cmath>

double Expr::BinaryNode::eval()
{
    switch (getID()) {
    case Token::ADD: return left_prt_->eval() + right_prt_->eval();
    case Token::SUB: return left_prt_->eval() - right_prt_->eval();
    case Token::MUL: return left_prt_->eval() * right_prt_->eval();
    case Token::DIV: return left_prt_->eval() / right_prt_->eval();
    case Token::CARET: return pow(left_prt_->eval(), right_prt_->eval());
    case Token::MOD: return fmod(left_prt_->eval(), right_prt_->eval());
    case Token::EQ: return left_prt_->eval() == right_prt_->eval();
    case Token::NEQ: return left_prt_->eval() != right_prt_->eval();
    case Token::LT: return left_prt_->eval() < right_prt_->eval();
    case Token::GT: return left_prt_->eval() > right_prt_->eval();
    case Token::LTE: return left_prt_->eval() <= right_prt_->eval();
    case Token::GTE: return left_prt_->eval() >= right_prt_->eval();
    case Token::AND: return left_prt_->eval() && right_prt_->eval();
    case Token::OR: return left_prt_->eval() || right_prt_->eval();
    default: return 0;
    }
};
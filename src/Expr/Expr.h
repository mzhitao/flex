#pragma once
#include "NodeBase.h"

namespace Expr {

class Expr
{
public:
    Expr() = delete;
    Expr(const std::string& expr) { paserExpr(expr); };

    double    eval() const { return root_prt_->eval(); };
    void      paserExpr(const std::string& expr);
    NodeBase* getRoot() const { return root_prt_; };

private:
    NodeBase*   root_prt_    = nullptr;
    NodeBase*   current_prt_ = nullptr;
    std::string expr_str_    = "";
};

}   // namespace Expr

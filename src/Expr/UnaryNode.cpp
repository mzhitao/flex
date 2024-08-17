#include "UnaryNode.h"
#include <boost/math/special_functions/gamma.hpp>


double Expr::UnaryNode::eval()
{
    switch (getID()) {
    case Token::BANG: return boost::math::tgamma(child_prt_->eval());
    default: return 0;
    }
};

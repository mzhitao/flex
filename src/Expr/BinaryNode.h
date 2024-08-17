#pragma once
#include "NodeBase.h"

namespace Expr {
class BinaryNode : public NodeBase
{

public:
    BinaryNode() = delete;
    BinaryNode(const BinaryNode& expr)
        : NodeBase(expr)
        , left_prt_(nullptr)
        , right_prt_(nullptr){};
    BinaryNode(BinaryNode&& expr)
        : NodeBase(std::move(expr))
        , left_prt_(nullptr)
        , right_prt_(nullptr){};
    BinaryNode& operator=(const BinaryNode&) = default;
    BinaryNode& operator=(BinaryNode&&)      = default;
    BinaryNode(const Token& token, NodeBase* parent, NodeBase* left, NodeBase* right)
        : NodeBase(token, parent)
        , left_prt_(left)
        , right_prt_(right)
    {}
    BinaryNode(const Token&& token, NodeBase* parent, NodeBase* left, NodeBase* right)
        : NodeBase(std::move(token), parent)
        , left_prt_(left)
    {}

    NodeBase* getLeft() const { return left_prt_; };
    NodeBase* getRight() const { return right_prt_; };
    void      setLeft(NodeBase* left) { left_prt_ = left; };
    void      setRight(NodeBase* right) { right_prt_ = right; };

    virtual ~BinaryNode() {}

    virtual double eval() override;

private:
    NodeBase* left_prt_  = nullptr;
    NodeBase* right_prt_ = nullptr;
};

}   // namespace Expr
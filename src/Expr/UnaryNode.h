#pragma once
#include "NodeBase.h"

namespace Expr {
class UnaryNode : public NodeBase
{

public:
    UnaryNode()                            = delete;
    UnaryNode(const UnaryNode& expr)       = delete;
    UnaryNode(UnaryNode&& expr)            = delete;
    UnaryNode& operator=(const UnaryNode&) = delete;
    UnaryNode& operator=(UnaryNode&&)      = delete;
    UnaryNode(const Token& token, NodeBase* parent, NodeBase* child)
        : NodeBase(token, parent)
        , child_prt_(child)
    {}
    UnaryNode(const Token&& token, NodeBase* parent, NodeBase* child)
        : NodeBase(std::move(token), parent)
        , child_prt_(child)
    {}
    NodeBase* getChild() const { return child_prt_; };
    void      setChild(NodeBase* child) { child_prt_ = child; };
    virtual ~UnaryNode() {}
    virtual double eval() override;

private:
    NodeBase* child_prt_ = nullptr;
};
}   // namespace Expr
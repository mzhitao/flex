#pragma once
#include "Mylexer/Token.h"

namespace Expr {

class NodeBase
{
public:
    NodeBase() = delete;
    NodeBase(const NodeBase& expr)
        : token(expr.token)
        , parent(nullptr){};
    NodeBase(NodeBase&& expr)
        : token(std::move(expr.token))
        , parent(nullptr){};
    NodeBase& operator=(const NodeBase&) = default;
    NodeBase& operator=(NodeBase&&)      = default;
    NodeBase(const Token& token, NodeBase* parent)
        : token(token)
        , parent(parent)
    {}
    NodeBase(const Token&& token, NodeBase* parent)
        : token(std::move(token))
        , parent(parent)
    {}

    NodeBase(const Token::Id id, const std::string& text)
        : token(Token(id, text)){};
    NodeBase(const Token::Id id, const std::string&& text)
        : token(Token(id, std::move(text))){};

    virtual ~NodeBase() {}


    const Token&   getToken() const { return token; };
    Token::Id      getID() const { return token.getID(); };
    Token::Type    getType() const { return token.getType(); };
    int            getPriority() const { return token.getPriority(); };
    Token::Assoc   getAssoc() const { return token.getAssoc(); };
    NodeBase*      getParent() const { return parent; };
    void           setParent(NodeBase* parent) { this->parent = parent; };
    virtual double eval() = 0;

private:
    Token     token;
    NodeBase* parent = nullptr;
};

}   // namespace Expr

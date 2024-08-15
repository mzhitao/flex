#pragma once
#include <map>
#include <string>

class Token
{
public:
    enum Id
    {
        ID,        //标识符
        CONST,     //常量
        FUNC,      //函数
        VAR,       //变量
        NUMBER,    //数字
        LPAREN,    //左括号
        RPAREN,    //右括号
        LSQUARE,   //左方括号
        RSQUARE,   //右方括号
        LCURLY,    //左大括号
        RCURLY,    //右大括号
        BANG,      //！
        CARET,     //^
        MUL,       //*
        DIV,       // /
        MOD,       //%
        PLUS,      // +
        NEG,       // -
        ADD,       //+
        SUB,       //-
        EQ,        //==
        NEQ,       //!=
        LT,        //<左
        GT,        //>右
        LTE,       // <=左
        GTE,       // >=右
        AND,       // &&
        OR,        // ||
        DOT,       // .
        COLON,     //分号
        ASSGN,     //赋值符 =
        COMMA,     //逗号
        EOL        //行

    };

    enum class Assoc   //运算符结合性
    {
        NONE,
        LEFT,
        RIGHT
    } ASS;

    enum class Type   //运算符
    {
        NONE,
        VAL,
        FUNC,
        SIGNE,   //符号
        UNARY,   //单目运算符
        BINARY   //双目运算符
    };

    Id   getID() const { return id_; }
    void setID(Id id) { id_ = id; }


    const std::string& getText() const { return text_; }

    int   getPriority() const;
    Type  getTokenType() const;
    Assoc getAssoc() const;



    Token() = delete;
    Token(Id id, const std::string& text)
        : id_(id)
        , text_(text){};

    ~Token();

private:
    static const std::map<std::string, double> constMap;
    Id                                         id_;
    std::string                                text_;
};

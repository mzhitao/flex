#pragma once
class Token
{
public:
    enum Type
    {
        WORD = 1,
        LINE,
        OTHER_CHAR
    };

    Token();
    ~Token();

private:
};

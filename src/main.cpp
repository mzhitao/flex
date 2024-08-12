#include <FlexLexer.h>
#include <iostream>

int main(int argc, char** argv)
{
    FlexLexer* mylexer = new yyFlexLexer;
    while (mylexer->yylex()) {
        std::cout << "token:" << mylexer->YYText() << std::endl;
    }

    return 0;
}
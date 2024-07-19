/**
 ****************************************************************************
 * Main
 ****************************************************************************
 *  Author : Anand Narwade
 *  Date   : 07-19-24 ( last update )
 *  file   : main.cpp
 ****************************************************************************
*/

#include <iostream>
#include "Config.h"

#include <iostream>
#include <memory>

STRING READ(const STRING& input);
STRING EVAL(const STRING& ast);
STRING PRINT(const STRING& ast);
STRING rep(const STRING& input);

static ReadLine s_readLine("~/.mal-history");

int main(int argc, char* argv[])
{
    STRING prompt = "user> ";
    STRING input;
    while (s_readLine.get(prompt, input)) {
        std::cout << rep(input) << "\n";
    }
    return 0;
}

STRING rep(const STRING& input)
{
    return PRINT(EVAL(READ(input)));
}

STRING READ(const STRING& input)
{
    return input;
}

STRING EVAL(const STRING& ast)
{
    return ast;
}

STRING PRINT(const STRING& ast)
{
    return ast;
}

/**
 ****************************************************************************
 * PROJECT CONFIGURATION
 ****************************************************************************
 *  Author : Anand Narwade
 *  Date   : 07-19-24
 *  file   : ReadLine.cpp
 ****************************************************************************
*/

/////////////////////////////////////////////////////////////////////////////////
/// INCLUDE
////////////////////////////////////////////////////////////////////////////////
#include "ReadLine.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

// TODO [1] : Find replacement for Readline lib 
// #include <unistd.h>
// #include <readline/readline.h>
// #include <readline/history.h>
// #include <readline/tilde.h>

#include <conio.h> // consol IO  TODO [1] remove this 
////////////////////////////////////////////////////////////////////////////////

static STRING readline(const STRING& prompt) {
    STRING input;
    char ch;
    std::cout << prompt;
    while (true) {
        ch = _getch();

        if (ch == '\r') { // Enter key
            std::cout << std::endl;
            break;
        }
        else if (ch == '\b') { // Backspace key
            if (!input.empty()) {
                input.pop_back();
                std::cout << "\b \b"; // Erase the last character from the console
            }
        }
        else if (ch == 27) { // Escape key
            input.clear();
            break;
        }
        else {
            input.push_back(ch);
            std::cout << ch;
        }
    }
    return input;
}

ReadLine::ReadLine() {

}

ReadLine::ReadLine(const STRING& historyFile)
//    : m_historyPath(copyAndFree(tilde_expand(historyFile.c_str()))) TODO [1] 
{
//     read_history(m_historyPath.c_str()); TODO [1]
}

ReadLine::~ReadLine(){
}

bool ReadLine::get(const STRING& prompt, STRING& out)
{
    STRING line = readline(prompt.c_str());
    if (line.empty()) {
        return false;
    }
    // TODO [1]
    // add_history(line); // Add input to in-memory history
    // append_history(1, m_historyPath.c_str());
    out = line;
    return true;
}

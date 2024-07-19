/**
 ****************************************************************************
 * PROJECT CONFIGURATION
 ****************************************************************************
 *  Author : Anand Narwade
 *  Date   : 07-19-24
 *  file   : temp.cpp
 ****************************************************************************
*/

/////////////////////////////////////////////////////////////////////////////////
/// INCLUDE
////////////////////////////////////////////////////////////////////////////////
#include "string_wrapper.h"
#include <stdarg.h>
////////////////////////////////////////////////////////////////////////////////

static int __strlen(const char* str, int idx) {
    if (str[idx] == '\0')
        return idx;
    return __strlen(str, idx + 1);
}

static int _strlen(const char* str) {
    return __strlen(str, 0);
}

STRING stringPrintf(const char* fmt, ...){
    int size = _strlen(fmt); // make a guess
    STRING str;
    va_list ap;
    while (true){
        str.resize(size);
        va_start(ap, fmt);
        int n = vsnprintf((char*)str.data(), size, fmt, ap);
        va_end(ap);
        if (n > -1 && n < size){
            str.resize(n);
            return str;
        }
        if (n > -1)
            size = n + 1;
        else
            size *= 2;
    }
	return str;
}

// convert c string to cpp string
STRING copyAndFree(char* mallocedString){
    STRING ret(mallocedString);
    free(mallocedString);
    return ret;
}

STRING escape(const STRING& in){
    STRING out;
    out.reserve(in.size() * 2 + 2); // each char may get escaped + two "'s
    out += '"';
    for (auto it = in.begin(), end = in.end(); it != end; ++it) {
        char c = *it;
        switch (c) {
        case '\\': out += "\\\\"; break;
        case '\n': out += "\\n"; break;
        case '"':  out += "\\\""; break;
        default:   out += c;      break;
        };
    }
    out += '"';
    out.shrink_to_fit();
    return out;
}

static char unescape(char c){
    switch (c){
        case '\\':  return '\\';
        case 'n':   return '\n';
        case '"':   return '"';
        default:    return c;
    }
}

STRING unescape(const STRING& in){
    STRING out;
    out.reserve(in.size()); // unescaped string will always be shorter
    for (auto it = in.begin() + 1, end = in.end() - 1;
              it != end; 
              ++it){
        char c = *it;
        if (c == '\\'){
            ++it;
            if (it != end)
                out += unescape(*it);
        }
        else{
            out += c;
        }
    }
    out.shrink_to_fit();
    return out;
}

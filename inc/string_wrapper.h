/**
 ****************************************************************************
 * TEMLATE HEADER
 ****************************************************************************
 *  Author : Anand Narwade
 *  Date   : 07-19-24
 *  file   : string_wrapper.h
 ****************************************************************************
*/

#ifndef __STRING_WRAPPER__
#define __STRING_WRAPPER__

#include <string>
#include <vector>

typedef std::string STRING;
typedef std::vector<STRING> VSTRING;

#define STRF        stringPrintf
#define PLURAL(n)   &("s"[(n)==1])

extern STRING stringPrintf(const char* fmt, ...);
extern STRING copyAndFree(char* mallocedString);
extern STRING escape(const STRING& in);
extern STRING unescape(const STRING& in);

#endif // __STRING_WRAPPER__
/**
 ****************************************************************************
 * TEMLATE HEADER
 ****************************************************************************
 *  Author : Anand Narwade
 *  Date   : 07-19-24
 *  file   : ReadLine.h
 ****************************************************************************
*/
#ifndef __READ_LINE_H__
#define __READ_LINE_H__

#include "string_wrapper.h"

class ReadLine {
public:
    ReadLine();
    ReadLine(const STRING& historyFile);
    ~ReadLine();

    bool get(const STRING& prompt, STRING& line);

private:
    STRING m_historyPath;
};

#endif // __READ_LINE_H__
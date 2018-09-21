#ifndef READER_H
#define READER_H

#include "page.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

class Reader
{
private:
    std::string input;
    std::string output;
public:
    Reader(std::string, std::string);
    void getData(DSvector<Page>&);
};

#endif // READER_H

#ifndef READER_H
#define READER_H

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
    void getData();
};

#endif // READER_H

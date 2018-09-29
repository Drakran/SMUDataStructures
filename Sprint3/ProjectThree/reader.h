#ifndef READER_H
#define READER_H

#include <string>
#include "DSvector.hpp"
#include <fstream>
#include <sstream>
#include <iostream>


class Reader
{
private:
    std::string input;
    std::string output;
    int totalWords;
    int printWords;
    DSvector<std::string> words;

public:
    Reader(std::string,std::string);
    void getData();
    void sortData();
    void printData();
};


#endif // READER_H

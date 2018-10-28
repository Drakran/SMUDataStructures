/*
 * The Reader class reads in the files and chooses where to output the file
 *
 * Terry Wang
 *
 * October 28th, 2018
 *
 * Fontenot and the Gang in, how do strings work?
 *
 */

#ifndef READER_H
#define READER_H

#include <string>
#include "adjlist.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

class Reader
{
public:
    Reader();
    Reader(std::string, std::string, std::string);
    void readData();
private:
    std::string input;
    std::string compare;
    std::string output;
    AdjList<std::string> list;
    //Learned Private is here because this is
    //the public facing thing, so private is not
    //important to most users
};

#endif // READER_H

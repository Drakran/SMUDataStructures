#ifndef LINKEDIN_H
#define LINKEDIN_H


#include <string>
#include "adjlist.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include "DSvector.hpp"

class LinkedIn
{
public:
    LinkedIn();
    void readData(std::string);
    void readCompare(std::string);
    void outputCompare(std::string);
private:
    std::string data;
    std::string compare;
    std::string output;
    AdjList<std::string> list;
    //Learned Private is here because this is
    //the public facing thing, so private is not
    //important to most users
};

#endif // LINKEDIN_H

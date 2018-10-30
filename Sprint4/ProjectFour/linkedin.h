#ifndef LINKEDIN_H
#define LINKEDIN_H


#include <string>
#include "adjlist.hpp"
#include "stack.hpp"
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
    DSvector<LinkedList<std::string>> connections;
    bool inStack();
    void findConnections(std::string,std::string);
    //Learned Private is here because this is
    //the public facing thing, so private is not
    //important to most users
};

#endif // LINKEDIN_H

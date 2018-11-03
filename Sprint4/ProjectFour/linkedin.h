#ifndef LINKEDIN_H
#define LINKEDIN_H



#include "adjlist.hpp"
#include "stack.hpp"
#include "DSvector.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class LinkedIn
{
public:
    LinkedIn();
    void readData(std::string);
    void readCompare(std::string);
    void outputData(std::string);
private:
    std::string data;
    std::string compare;
    std::string output;
    AdjList<std::string> list;
    DSvector<std::string> shortDistance;
    int findConnections(std::string);
    void backtrack(std::string,std::string);
    int findShortestDistance(DSvector<Stack<std::string>>);
    //Learned Private is here because this is
    //the public facing thing, so private is not
    //important to most users
};

#endif // LINKEDIN_H

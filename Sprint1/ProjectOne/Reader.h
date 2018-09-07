#ifndef READER_H
#define READER_H

#include<string>
#include "user.h"
#include <vector>
#include <algorithm>

class Reader{
private:
    std::string name;//First File Name(tweets)
    std::string libName;//2nd File(
    std::string outName;

public:
    Reader(std::string, std::string,std::string);
    void getData(vector<User> &);
    void getLibs(vector<User> &, vector<string> &);
    string writeLibs(vector<User> &,string, string, string);
    void printLibs();
};
#endif // READER_H

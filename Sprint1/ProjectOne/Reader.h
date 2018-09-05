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
public:
    Reader(std::string, std::string);
    void getData(vector<User*> &);
    void getLibs(multimap<string,string> &);
};
#endif // READER_H

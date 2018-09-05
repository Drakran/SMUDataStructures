#ifndef READER_H
#define READER_H

#include<string>
#include "user.h"
#include <vector>

class Reader{
private:
    std::string name;
    //std::string delim;
public:
    Reader(std::string);
    void getData(vector<User*> &);
};
#endif // READER_H

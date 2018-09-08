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
    void printLibs(vector<string> &);
    //void printStatistics();
    void calculateStatistics(vector<User> &, vector<string> &);

};
#endif // READER_H

/*Note I realize after the fact that I should've just made
//the Vector<user> an instance variable but its too late, lessons learned
//I Guess if you want mulitple user vectors its better but in this case no
*/

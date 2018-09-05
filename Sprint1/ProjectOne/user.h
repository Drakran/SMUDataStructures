#ifndef USER_H
#define USER_H

#include <string>
#include <map>

using namespace std;

class User
{
private:
    string id;
    string name;
    multimap<string,string> tweet;
    string mood;
public:
    User(string,string,multimap<string,string>,string);
    string getID();
    string getName();
    multimap<string,string> getTweet();
    string getMood();
};

#endif // USER_H

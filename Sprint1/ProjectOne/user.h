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
    static int numTweet;
    User(string,string,multimap<string,string>,string);
    string getID();
    string getName();
    multimap<string,string> getTweet();
    string getMood();
    static int getTotalTweets()
    {
        return numTweets;
    }

    static int getPositiveTweets();
    static int getNegativeTweets();
};

#endif // USER_H

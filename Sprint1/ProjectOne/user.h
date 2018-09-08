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
    static int numTweet;
    static int posTweet;
    static int negTweet;
    static int posAvgWords;
    static int negAvgWords;

public:
    User(string,string,multimap<string,string>,string);
    string getID();
    string getName();
    multimap<string,string> & getTweet();
    string getMood();
    static int getTotalTweets();
    static int getPositiveTweets();
    static int getNegativeTweets();
//    static int getPosAvg();
//    static int getNegAvg();
//    static void setPosAvg();
//    static void setNegAvg();
};

#endif // USER_H

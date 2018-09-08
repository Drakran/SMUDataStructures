#ifndef USER_H
#define USER_H
/* Terry Wang
 * Sept 8th, 2018 4:45am(HALP)
 * Data Structures Fontnenot
 * The user class is designed to hold the users
 * and is designed to contain one user for each tweet
 * while also containing the entirety of the tweet data
 * linked to the user.
 */

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

public:
    User(string,string,multimap<string,string>,string);
    string getID();
    string getName();
    multimap<string,string> & getTweet();
    string getMood();
    static int getTotalTweets();
    static int getPositiveTweets();
    static int getNegativeTweets();
};

#endif // USER_H

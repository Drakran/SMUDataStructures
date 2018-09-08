#include <iostream>
#include "Reader.h"
#include "user.h"

#include <fstream>

using namespace std;

int User::numTweet = 0;
int User::posTweet = 0;
int User::negTweet = 0;
int User::posAvgWords = 0;
int User::negAvgWords = 0;

int main(int argc, char *argv[])
{
    vector<User> users;
    vector<string> output;
    Reader scanner(argv[1],argv[2],argv[3]);
    scanner.getData(users);
//    scanner.getLibs(users,output);
    scanner.printLibs(output);
    scanner.calculateStatistics(users,output);
//    for(int x = 0; x < output.size(); x++)
//    {
//        cout << output[x] << endl;
//    }
//    cout << User::getTotalTweets() << endl;
//    cout << User::getPositiveTweets() << endl;
//    cout << User::getNegativeTweets() << endl;


//    for(int x = 0; x < parts.size(); x++)
//    {
//        cout << parts[x];
//    }

    //scanner.writeLibs(users,madUsers);
    //cout << users[1]->getName();
//    for(int x = 0; x < users.size(); x++)
//    {
//        if(true)
//        {
//            cout << users[x].getName();
//            for(auto temp : users[x].getTweet())
//            {
//                cout << temp.first << " " << temp.second << endl;
//            }
//        }
//    }

//    for(auto x = madUsers.begin(); x != madUsers.end(); x++)
//    {
//        cout<< x->first << " " << x->second << endl;//
//    }


    return 0;
}

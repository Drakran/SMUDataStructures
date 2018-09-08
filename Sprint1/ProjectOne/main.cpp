/* Terry Wang
 * Sept 8th, 2018 4:45am(HALP)
 * Data Structures Fontnenot
 */

#include <iostream>
#include "Reader.h"
#include "user.h"
#include "time.h"
#include <fstream>

using namespace std;

//Static Variables for User
int User::numTweet = 0;
int User::posTweet = 0;
int User::negTweet = 0;

int main(int argc, char *argv[])
{
    srand(time(0)); //Super Random
    vector<User> users;
    vector<string> output;
    Reader scanner(argv[1],argv[2],argv[3]);
    scanner.getData(users); //Gets all the tweets into users
    scanner.calculateStatistics(users,output);
    scanner.getLibs(users,output); //Gets all the madLib
    scanner.printLibs(output);//Prints Everything
    return 0;
}

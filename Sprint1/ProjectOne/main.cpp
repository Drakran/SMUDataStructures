#include <iostream>
#include "Reader.h"
#include "user.h"

#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    vector<User> users;
    //multimap<string,string> madUsers;
    vector<string> output;
    //cout << argv[0] << endl;
    Reader scanner(argv[1],argv[2],argv[3]);
    //cout << argv[1] << endl;
    scanner.getData(users);
    scanner.getLibs(users,output);
    //scanner.writeLibs(users,madUsers);
    //cout << users[1]->getName();
//    for(int x = 0; x < users.size(); x++)
//    if((users[x].getName()) == "aristocracy")
//    {
//        cout << users[x].getName();
//        for(auto temp : users[x].getTweet())
//        {
//            cout << temp.first << " " << temp.second << endl;
//        }
//    }
//    for(auto x = madUsers.begin(); x != madUsers.end(); x++)
//    {
//        cout<< x->first << " " << x->second << endl;//
//    }


    return 0;
}

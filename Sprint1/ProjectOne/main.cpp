#include <iostream>
#include "Reader.h"
#include "user.h"

#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    vector<User*> users;
    multimap<string,string> madUsers;
    Reader scanner(argv[1],argv[2]);
    //cout << argv[1] << endl;
    scanner.getData(users);
    //cout << users[1]->getName();
    for(int x = 0; x < 25; x++)
    if((users[x]->getName()) == "aristocracy")
    {
        cout << users[x]->getName();
        for(auto temp : users[x] -> getTweet())
        {
            cout << temp.first << " " << temp.second << endl;
        }
    }

    return 0;
}

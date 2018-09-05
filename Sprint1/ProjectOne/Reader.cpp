#include "Reader.h"
#include <fstream>
#include <sstream>
#include <iostream>


using namespace std;

Reader::Reader(string fileName,string madLibName)
{
    name = fileName;
    libName = madLibName;
}

/* getData gets the data from a csv twitter file and stores
 * each line as a user object
 * @param the vector of user objects that all users will be stored in
 */
void Reader::getData(vector<User*> & users)
{
    ifstream file;
    file.open(name);
    //Exits if no file
    if(!file)
    {
        cout << "Error, can't open file" << endl;
        exit(EXIT_FAILURE);
    }
    string line; //String to ignore first line
    string tuple; //The whole tuple
    string id,user,word,speech,mood;
    multimap<string,string> tweeter;
    string garbage;
    getline(file,line); //Ignores First Line
    getline(file,id,','); //Gets the first id
    while(file.good())
    {
        getline(file,user,',');
        getline(file,tuple,']'); //Gets the whole tuple
        stringstream tweet(tuple); //Converts that tuple into a stream
        /*While loop seperates the word and part of speech, removes the'',
        and stores in a multimap*/
        while(getline(tweet,garbage,'('))
        {
            getline(tweet,word,',');
            word.erase(remove(word.begin(),word.end(), '\''), word.end());
            getline(tweet,speech,')');
            speech.erase(remove(speech.begin(),speech.end(), '\''), speech.end());
            //cout << speech << endl;
            tweeter.insert(pair<string,string>(speech,word));
        }
        getline(file,mood,'\n');

        User * temp = new User(id,user,tweeter,mood);
        users.push_back(temp);
        tweeter.clear(); //Clears the multimap for reuse
        getline(file,id,','); //To test file.good()
    }

    file.close();
}

void Reader::getLibs(multimap<string,string> &madUsers)
{
    ifstream file;
    file.open(libName);

    if(!file)
    {
        cout << "Error, can't open file" << endl;
        exit(EXIT_FAILURE);
    }

    string name, partSpeech ,garbage;
    getline(file,name,' ');
    while(file.good())
    {


        getline(file,garbage, '[');
        getline(file,partSpeech, ']');
        getline(file,garbage, '\n');

        madUsers.insert(pair<string,string>(name,partSpeech));

        getline(file,name,' ');
    }
    file.close();
}



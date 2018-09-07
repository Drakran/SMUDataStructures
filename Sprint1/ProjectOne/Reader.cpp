#include "Reader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex> //I barely know what that is but It helped a lot


using namespace std;

Reader::Reader(string fileName,string madLibName,string outputName)
{
    name = fileName;
    libName = madLibName;
    outName = outputName;
}

/* getData gets the data from a csv twitter file and stores
 * each line as a user object
 * @param the vector of user objects that all users will be stored in
 */
void Reader::getData(vector<User> & users)
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
            speech = speech.substr(1,speech.length()-1);
            speech.erase(remove(speech.begin(),speech.end(), '\''), speech.end());
            //cout << speech << endl;
            tweeter.insert(pair<string,string>(speech,word));
        }
        getline(file,garbage, ',');
        getline(file,mood,'\n');

        User  temp = User(id,user,tweeter,mood);
        users.push_back(temp);
        tweeter.clear(); //Clears the multimap for reuse
        getline(file,id,','); //To test file.good()
    }

    file.close();
}

void Reader::getLibs(vector<User>& user, vector<string> & output)
{
    ifstream file;
    file.open(libName);
    if(!file)
    {
        cout << "Error, can't open file" << endl;
        exit(EXIT_FAILURE);
    }
    string statement; //Whole Line
    string name, partSpeech ,garbage;
    getline(file,name,' ');
    while(file.good())
    {
        getline(file,statement, '\n'); //Gets the whole line
        stringstream lib(statement);
        //cout << statement << endl;
        //Now to partition the lib and find the part of speech to replace
        getline(lib,garbage, '[');
        getline(lib,partSpeech, ']');
       // cout << partSpeech << endl;
        getline(lib,garbage, '\n');
        output.push_back(writeLibs(user,statement,name,partSpeech));
        //madUsers.insert(pair<string,string>(name,partSpeech));

        getline(file,name,' ');
    }
    file.close();
}

string Reader::writeLibs(vector<User> & users,string statement,
                         string madUser, string speech)
{
    vector<string> newWord;
    int count{0};
    for(unsigned int x = 0; x < users.size(); x++)
    {
        if(users[x].getName() == madUser)
        {

            multimap<string,string> temp = users[x].getTweet();
            for(auto mad = temp.begin(); mad != temp.end();  mad++)
            {
                regex r("\\b" + (speech) + "\\b"); //GETS ONLY THAT WORD(This took an hour to learn regex)
                smatch m; //Not really sure but it matches on a string
                string part = mad->first; //the part of speech
                if(regex_search(part,m,r) /*part.find(speech) != string::npos && part.find(' ') != string::npos*/)
                {
//                    cout << madUser << " " << speech << " " << part
//                        << " " << mad->second << endl;
                    string word = mad->second;
                    newWord.push_back(word);
                    count++;
                }
            }
//            //range is the pair of iterator that will make up the range of the map with only the correct partofspeech
//            pair<multimap<string,string>::iterator
//                    ,multimap<string,string>::iterator> range;
//            range = (users[x].getTweet()).equal_range(speech);//returns an iterator with only the keys of speech
//            size_t sizeMap = distance(range.first,range.second);//size of iterator
//            if(sizeMap != 0)
//            {

//                size_t index = rand() % sizeMap; //Random Index
//                advance(range.first,index);
//                string word = (range.first)->first;
//                cout << word;
//                newWord.push_back(word);
//            }
        }
    }
    if(count == 0) {count = 1;} //Just in case somehow the word is not in there itll get something
    size_t index = rand() % count; //Random NUmber thats not really random number
    string finalWord = newWord[index];//The finalword is a random word thats selected to be put in
    string completedTweet = regex_replace(statement, regex(speech), finalWord); //replace
    completedTweet = madUser + " " + completedTweet;
 //   cout << completedTweet << endl;
    return completedTweet;
}

void Reader::printLibs()
{

}

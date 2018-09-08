#include "Reader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <regex> //I barely know what that is but It helped a lot


using namespace std;
/*
 * The Reader Constructor takes in a fileName for the tweets
 * A madLibName for the madLibFIle
 * and an output Name for the output name
 * @param fileName the tweet filename
 * @param madLibName the madLibName
 * @param outputName the output file name
 */
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
            word.erase(remove(word.begin(),word.end(), '\"'), word.end());
            getline(tweet,speech,')');
            speech = speech.substr(1,speech.length()-1);
            speech.erase(remove(speech.begin(),speech.end(), '\''), speech.end());
            if(speech.find("COMMA") != string::npos)
            {
                speech = "COMMA";
                word = ',';
            }
            tweeter.insert(pair<string,string>(speech,word));
        }
        getline(file,garbage, ',');
        getline(file,mood,'\n');

        User temp = User(id,user,tweeter,mood);
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
                /*This Commented out code is if you want...
                /Adjective == (Adjective or Numeral)
                in if statement()
                */
                regex r("\\b" + (speech) + "\\b"); //GETS ONLY THAT WORD
                smatch m; //Not really sure but it matches on a string
                string part = mad->first; //the part of speech
                if(regex_search(part,m,r))
                {
                    string word = mad->second;
                    newWord.push_back(word);
                    count++;
                }
            }
        }
    }
    if(count == 0) {count = 1;} //If word is not there
    size_t index = rand() % count; //Pseudo -Random
    string finalWord = newWord[index];//Finalword
    string completedTweet = regex_replace(statement, regex(speech), finalWord); //replace
    completedTweet = madUser + " " + completedTweet;
    return completedTweet;
}

void Reader::printLibs(vector<string> & output)
{
    ofstream outFile;
    outFile.open(outName);
    for(auto out: output)
    {
        outFile << out << '\n';
    }
    outFile.close();
}

/*
 */
void Reader::calculateStatistics(vector<User> & users, vector<string> & output)
{
    vector<string> parts = {"ADJECTIVE",
    "ADJECTIVE OR NUMERAL",
    "ADVERB",
    "CLOSING PARENTHESIS",
    "CLOSING QUOTATION MARK",
    "COLON OR ELLIPSIS",
    "COMMA",
    "CONJUNCTION",
    "DETERMINER",
    "DOLLAR",
    "EXISTENTIAL THERE",
    "FOREIGN WORD",
    "GENITIVE MARKER",
    "HASHTAG",
    "INTERJECTION",
    "MODAL AUXILIARY",
    "NOUN",
    "NUMBER",
    "NUMERAL",
    "OPENING PARENTHESIS",
    "PARTICLE",
    "PREPOSITION OR CONJUNCTION",
    "PRONOUN",
    "SENTENCE TERMINATOR",
    "SYMBOL",
    "TO",
    "URL",
    "USERNAME",
    "VERB"};
    cout.precision(3);
    double posAvg{0};
    double negAvg{0};
    map<string,map<string,int>> speechPosWords;
    map<string,map<string,int>> speechNegWords;
    bool posTrue = false;
    bool negTrue = false;
    for(auto partSpeech: parts)
    {
        posTrue = false;
        negTrue = false;
        map<string,int> posWords; //Pos and neg Words to be put into a specific part of speech
        map<string,int> negWords;
        for(auto user: users)
        {

            multimap<string,string> userMap = user.getTweet(); //Gets the multimap of a user
            pair<multimap<string,string>::iterator,multimap<string,string>::iterator> range;
            range = userMap.equal_range(partSpeech); //Only the part of speeches
            int count = distance(range.first,range.second);
            if(count != 0)
            {
                if(user.getMood() == "0")
                {
                    negTrue = true;
                    for(multimap<string,string>::iterator iter = range.first;
                        iter != range.second; iter++)
                    {
                        string tempWord = iter->second;
                        ++negWords[tempWord];

                    }
                }
                else
                {
                    posTrue = true;
                    for(multimap<string,string>::iterator iter = range.first;
                        iter != range.second; iter++)
                    {
                        string tempWord = iter->second;
                        ++posWords[tempWord];

                    }
                }
            }

            //tweeter.insert(pair<string,string>(speech,word));



        }
        if(posTrue)
        {
            speechPosWords.insert(pair<string,map<string,int>>(partSpeech,posWords));

        }
        if(negTrue)
        {
            speechNegWords.insert(pair<string,map<string,int>>(partSpeech,negWords));
        }
    }

    //This is finalzing the variables and sending it into print

    /*This is getting the Average based on size of map
     * (i.e. number of parts of speeches)
     */

    //Positive Loop to add up Count
    for(auto outerLoop: speechPosWords)
    {
        for(auto count: outerLoop.second)
        {
            posAvg += count.second;
        }
    }
    //If num positive = 0, pos AVg = 0
    cout << posAvg << endl;
    if(User::getPositiveTweets() != 0)
    {
        posAvg = (posAvg/User::getPositiveTweets());
    }
    //Negative Loop to add Count
    for(auto outerLoop: speechNegWords)
    {
        for(auto count: outerLoop.second)
        {
            negAvg += count.second;
        }
    }
    if(User::getNegativeTweets() != 0)
    {
        negAvg = (negAvg/User::getNegativeTweets());
    }

    //Sending Avg Number to output
    string finalPosString;
    finalPosString = "The Average Words(Part of Speech) for Positive Tweet is:" + to_string(posAvg);
    finalPosString = finalPosString + '\n';
    string finalNegString;
    finalNegString = "The Average Words(Part of Speech) for Negative Tweet is:" + to_string(negAvg);
    finalNegString = finalNegString + '\n';

    //Push the Avg Number Strings to output
    output.push_back(finalPosString);
    output.push_back(finalNegString);


    //Setting up output for next part
    string posT = "Positive Tweet Number of Words per Part of Speech";
    posT = posT + '\n';
    output.push_back(posT);

    //Number of words per part of speech
    int totalWords = 0;
    for(unsigned int speech = 0; speech < parts.size(); speech++)
    {
        totalWords = 0;
        string grammarTitle = parts[speech];
        for(auto outerLoop: speechPosWords)
        {
            //If the partofSpeech is the same as the one in the map
            if(outerLoop.first == grammarTitle)
            {
                for(auto count: outerLoop.second)
                {
                    totalWords += count.second;
                }
            }

        }
    string numPos = "The Number of " + grammarTitle + " is " + to_string(totalWords);
    numPos = numPos + ".";
    output.push_back(numPos);
    }

    //Setting up output for next part
    string whiteSpace = "----------------------------" + '\n';
    output.push_back(whiteSpace);
    string posN = "Negative Tweet Number of Words per Part of Speech";
    posN = posN + '\n';
    output.push_back(posN);

    for(unsigned int speech = 0; speech < parts.size(); speech++)
    {
        totalWords = 0;
        string grammarTitle = parts[speech];
        for(auto outerLoop: speechNegWords)
        {
            //If the partofSpeech is the same as the one in the map
            if(outerLoop.first == grammarTitle)
            {
                for(auto count: outerLoop.second)
                {
                    totalWords += count.second;
                }
            }

        }
    string numNeg = "The Number of " + grammarTitle + " is " + to_string(totalWords);
    numNeg = numNeg + ".";
    output.push_back(numNeg);

    }

    //Setup Output for Next Part
    string spaceNew = "----------------------------" + '\n';
    output.push_back(spaceNew);
    string threeP = "The Top three words for Positive Tweets";
    threeP = threeP + '\n';
    output.push_back(threeP);

    //Top Three Word Method

    for(unsigned int speech = 0; speech < parts.size(); speech++)
    {
        multimap<int,string, greater <int>> finalMap;
        vector<string> topThree = {"N/A", "N/A", "N/A"};
        string grammarTitle = parts[speech];
        for(auto outerLoop: speechPosWords)
        {
            //If the partofSpeech is the same as the one in the map
            if(outerLoop.first == grammarTitle)
            {
                map<string,int> tempHolds = outerLoop.second;
                for(auto iter: tempHolds)
                {
                    //Reverse the map so we can sort by intergers
                    //This leaves the map sorted
                    finalMap.insert(pair<int,string>(iter.second,iter.first));
                }
            }

        }
        //Gets the Top three if there are three, otherwise put in as many as can
            multimap<int,string, greater <int>>::iterator iter = finalMap.begin();

            for(unsigned int z = 0; z < finalMap.size() && z < 3; z++)
            {
                    topThree[z] = iter->second;
                    advance(iter,1);
            }

            string three = "The Top Three words in " + grammarTitle;
            three = three + " are " + topThree[0];
            three = three + "," + topThree[1];
            three = three + ",and " + topThree[2];
            output.push_back(three);
       }

    //Setup Output for Next Part
    string space = "----------------------------" + '\n';
    output.push_back(space);
    string threeN = "The Top three words for Negative Tweets";
    threeN = threeN + '\n';
    output.push_back(threeN);

    for(unsigned int speech = 0; speech < parts.size(); speech++)
    {
        multimap<int,string, greater <int>> finalMap;
        vector<string> topThree = {"N/A", "N/A", "N/A"};
        string grammarTitle = parts[speech];
        for(auto outerLoop: speechNegWords)
        {
            //If the partofSpeech is the same as the one in the map
            if(outerLoop.first == grammarTitle)
            {
                map<string,int> tempHolds = outerLoop.second;

                for(auto iter: tempHolds)
                {

                    finalMap.insert(pair<int,string>(iter.second,iter.first));
                }
            }

        }
        //Gets the Top three if there are three, otherwise less than three
            multimap<int,string, greater <int>>::iterator iter = finalMap.begin();
            for(unsigned int z = 0; z < finalMap.size() && z < 3; z++)
            {
                    topThree[z] = iter->second;
                    advance(iter,1);
            }
            string three = "The Top Three words in " + grammarTitle;
            three = three + " are " + topThree[0];
            three = three + "," + topThree[1];
            three = three + ",and " + topThree[2];
            output.push_back(three);
       }
    //Setup For next block of text(I didn't plan this that well)
    string spaceLast = "----------------------------" + '\n';
    output.push_back(spaceLast);
    string finalLibs ="THE LIBS";
    output.push_back(finalLibs);
}





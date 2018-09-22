/* The reader class reads in the data from the sample and
 * pharses it out into strings that the page class will take
 *
 * Terry Wang
 *
 * September 21st, 2018
 */

#include "reader.h"
#include "DSvector.hpp"



using namespace std;

Reader::Reader(string inputFile, string outputFile)
{
    input = inputFile;
    output = outputFile;
}

/* getData opens the input file and then pharses
 * out each string from each page given and
 * creates a page before sending the page to the
 * page vector
 * @param pages the page vector
 */
void Reader::getData(DSvector<Page>& pages)
{
    ifstream file;
    file.open(input);

    if(!file)
    {
        cerr << "Error, file not opening mate" << '\n';
        exit(EXIT_FAILURE);
    }
    //test
    char cha;
    char garbage;
    int page = 0;
    bool end = false; //If false, <-1> hasn't been reached
    file.get(cha); //Makes sure that the check below works
    while(file.good())
    {
        DSvector<string> tempWords;
        //Used to get the page number by comparing with the < in front of
        //every page number
        if(cha == '<')
        {
            string tempPageNum;
            getline(file,tempPageNum, '>');
            if(tempPageNum != "-1")
            {
                page = stoi(tempPageNum); //Converts string to int
                //cout << "PAGE:" << page << '\n';
                file.get(garbage); //Flush out the >
            }
            else
            {
                end = true; //-1 has been reached
            }
        }
        file.get(cha); //First char so it can be compared
        //Goes on until a new page number is reached "<"
        while(cha != '<' && end == false)
        {
            //Word to push back into a vector of all words for that page
            string word;
            //If its a phrase, append each char till]
            if(cha == '[')
            {
                file.get(cha);//removes the [
                while(cha != ']')
                {
                    word += cha;
                    file.get(cha);
                }
                file.get(garbage); //should be the space or '\n
            }
            //If its not a phrase but a regular word do this
            else
            {
                while(cha != ' ' && cha != '\n')
                {

                    word += cha;
                    file.get(cha);
                }
            }
            transform(word.begin(),word.end(),word.begin(),::tolower); //toLowercase
            word.erase(remove_if(word.begin() ,word.end() , ::ispunct), word.end());
            //cout << word << '\n';
            tempWords.put_back(word);//puts the completed word
            file.get(cha);
        }
        Page temp = Page(page,tempWords);//Creates temp objects of Page
//        for(int x = 0; x < tempWords.getSize(); x++)
//        {
//            cout << tempWords[x] << '\n';
//        }
        try
        {
            pages.put_back(temp);//Put the page into the PAGE Vector
        } catch (const exception& e)
        {
            cerr << e.what();
        }

        tempWords.clear();
    }
}

void Reader::sortData(DSvector<Page>& pages, DSvector<Word>& words)
{

}

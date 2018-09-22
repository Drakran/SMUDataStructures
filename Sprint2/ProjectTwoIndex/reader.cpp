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
    file.close();
}

/* sortData collects all the words into a vector and matches then up with
 * a pagenumber, storing that into a Word Vector for FINAL PROCESSING
 * @param pages the vector with all the pages
 * @words the vector that contains the final sorted words
 */
void Reader::sortData(DSvector<Page>& pages, DSvector<Word>& words)
{
    DSvector<string> allWords; //Has all the words
    try
    {
        for(int x = 0; x < pages.getSize(); x++)
        {
            DSvector<string> tempWords = pages[x].getWords();
            for(int y = 0; y < tempWords.getSize(); y++){
                allWords.put_back(tempWords[y]);
            }
        }
    } catch (const exception& e)
    {
        cerr << "Error reading in allWords" << e.what();
    }

    rmvDuplicate(allWords);
    allWords.sort();
    for(int x = 0; x < allWords.getSize(); x++)
    {
        string compare = allWords[x];
        words.put_back(matchPageWord(pages,compare));
    }

//    for(int z =0; z < words.getSize(); z++)
//    {
//        cout << words[z].getWord();
//        for(int x =0; x < (words[z].getPageNums()).getSize(); x++)
//        {
//            cout << (words[z].getPageNums())[x] << " ";
//        }
//        cout << '\n';
//    }
}


/*rmv Duplicate removes all dupliactes in the vector that contains all the strings
 * @param word which is the word vector with all the words possible
 */
void Reader::rmvDuplicate(DSvector<string>& word)
{
    int x,y;
    string check; //Word to be checked
    for(x = 0; x < word.getSize(); x++)
    {
        check = word[x];
        for(y = x + 1; y <word.getSize(); y++)
        {
            if(check.compare(word[y]) == 0)
            {
                word.erase(y);
                y--; //SO don't skip elements
            }
        }
    }
}

/* matchPageword matches the words to the pages, while
 * also dealing with multiple pages to one words and
 * duplicate words
 * @param pages the page vector
 * @param cmp the string that all the pages are being mapped too
 * @return finished is the final word with a vector of ints containing the
 * page number
 */
Word Reader::matchPageWord(DSvector<Page>& pages, string cmp)
{
    DSvector<int> tempNums;
    for(int x = 0; x < pages.getSize(); x++)
    {
        DSvector<string> compareWord = pages[x].getWords();
        for(int y = 0; y < compareWord.getSize(); y++)
        {
            //If the word matches a word on the page
            if(cmp.compare(compareWord[y]) == 0)
            {
                int pageNum = pages[x].getPageNum();
                if(!tempNums.isEmpty())
                {
                    for(int j = 0; j < tempNums.getSize(); j++)
                    {
                        if(pageNum != tempNums[j])
                        {
                            tempNums.put_back(pageNum);
                        }
                    }
                }
                else
                {
                    tempNums.put_back(pageNum);
                }
            }
        }
    }
    tempNums.sort();
    Word finished(cmp,tempNums);
    return finished;
}

/* The printOutput method makes the header and prints everything out
 * @param words the vector containing the finished words
 */
void Reader::printOutput(DSvector<Word>& words)
{
    ofstream outFile;
    outFile.open(output);
    DSvector<string> headers; //Temp vector for all the headers
    for(int x = 0; x < words.getSize(); x++)
    {
        string temp = words[x].getWord();
        string header = temp.substr(0,1);
        headers.put_back(header);
    }
    rmvDuplicate(headers);
    for(int x = 0; x < headers.getSize(); x++)
    {
        string head = headers[x];
        outFile << "[" << head << "]" << '\n';
        //Go through through the word array
        for(int i = 0; i < words.getSize(); i++)
        {
            string word = words[i].getWord();
            //If the word starts with the header print
            if(word.substr(0,1) == head)
            {
                outFile << word << ": ";
                //Prints out the page nums
                for(int y = 0; y < words[i].getPageNums().getSize(); y++)
                {
                    outFile << words[i].getPageNums()[y];
//                    if(iter = )
                }
                outFile << '\n';
            }
        }
    }
    outFile.close();
}

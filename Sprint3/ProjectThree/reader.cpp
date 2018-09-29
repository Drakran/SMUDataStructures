#include "reader.h"

using namespace std;

Reader::Reader(string in, string out)
{
    input = in;
    output = out;
    totalWords = 0; //Default
    printWords = 0; //Default
}

//Reads the Data
void Reader::getData()
{
    ifstream file;
    file.open(input);

    if(!file)
    {
        cerr << "Error, file doesn't open" << '\n';
        exit(EXIT_FAILURE);
    }

    int totalWords;
    int numPrintWords;

    //Reads first two lines for criteria
    file >> totalWords;
    file.ignore();
    file >> numPrintWords;
    file.ignore();

    this->totalWords = totalWords;
    this->printWords = numPrintWords;

    int count = 0;
    while(count < totalWords)
    {
        string tempWord;
        int length;
        getline(file,tempWord);
        length = static_cast<int>(tempWord.length());
        Word tempCompletedWord(tempWord,length);
        words.put_back(tempCompletedWord);
        count++;
    }
    file.close();
//    for(int x = 0; x < words.getSize(); x++)
//    {
//        cout << words[x].word << '\n';
//    }
}

//Sorts the Data under the two criteria
//Sort by length, then by alphabetical order
void Reader::sortData()
{
    words.sort(0,words.getSize() - 1);
}

void Reader::printData()
{
    ofstream outFile;
    outFile.open(output);
    cout << "A Sorted List Happened!" << '\n';
    for(int x = 0; x < printWords; x++)
    {
        cout << words[x].word << '\n';
    }
    outFile.close();
}

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

    //Reads till all words are read
    int count = 0;
    while(count < totalWords)
    {
        string tempWord;
        int length;
        getline(file,tempWord);
        length = static_cast<int>(tempWord.length());
        Word tempCompletedWord(tempWord,length); //Creates word Object
        words.put_back(tempCompletedWord);
        count++;
    }
    file.close();
}

//Sorts the Data under the two criteria
//Sort by length, then by alphabetical order
void Reader::sortData()
{
    words.sort(0,words.getSize() - 1);
}

//Prints the data to an output
void Reader::printData()
{
    ofstream outFile;
    outFile.open(output);
    cout << "A Sorted List Happened!" << '\n';
    for(int x = 0; x < printWords; x++)
    {
        outFile << words[x].word << '\n';
    }
    outFile.close();
}

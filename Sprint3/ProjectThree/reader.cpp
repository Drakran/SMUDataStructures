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
    file >> numPrintWords;

    this->totalWords = totalWords;
    this->printWords = numPrintWords;

    string garbage; //gets \n, replace with ignore
    getline(file,garbage);

    while(file.good())
    {
        string tempWord;
        getline(file,tempWord);
        words.put_back(tempWord);
    }
    file.close();
}

//Sorts the Data under the two criteria
//Sort by length, then by alphabetical order
void Reader::sortData()
{

}

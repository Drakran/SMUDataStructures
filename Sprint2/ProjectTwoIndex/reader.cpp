#include "reader.h"

using namespace std;

Reader::Reader(string inputFile, string outputFile)
{
    input = inputFile;
    output = outputFile;
}

void Reader::getData()
{
    ifstream file;
    file.open(input);

    if(!file)
    {
        cerr << "Error, file not opening mate" << '\n';
        exit(EXIT_FAILURE);
    }
    //test
    string line;
    while(file.good())
    {
        getline(file,line);
        cout << line << '\n';
    }
}

#include "Reader.h"
#include <fstream>
#include <iostream>

using namespace std;

Reader::Reader(string fileName)
{
    name = fileName;
    cout << name;
}

void Reader::getData()
{
    ifstream file;
    file.open(name);
    //Exits if no file
    if(!file)
    {
        cout << "Error, can't open file" << endl;
        exit(EXIT_FAILURE);
    }

    string line;

    while(getline(file,line,','))
    {
        cout << line;
    }



}



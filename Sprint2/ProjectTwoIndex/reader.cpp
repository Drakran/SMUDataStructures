#include "reader.h"
#include "DSvector.hpp"


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
    char cha;
    char garbage;
    int page;
    bool end = false;
    file.get(cha); //Makes sure that the check below works
    while(file.good())
    {

        if(cha == '<')
        {
            string tempPageNum;
            getline(file,tempPageNum, '>');
            if(tempPageNum != "-1")
            {
                page = stoi(tempPageNum); //Converts string to int
                cout << "PAGE:" << page << '\n';
                file.get(garbage); //Flush out the >
            }
            else
            {
                end = true;
                cout << "END SUCESS";
            }
        }
        file.get(cha); //First line
        while(cha != '<' && end == false)
        {
            string word;//Word to push back into a vector of all words for that page
            //int count = 0;
            if(cha == '[')
            {
                file.get(cha);//removes the [
                while(cha != ']')
                {
                    word += cha;
                    file.get(cha);
                }
                file.get(garbage); //should be the space
            }
            else
            {
                while(cha != ' ' && cha != '\n')
                {

                    word += cha;
                    file.get(cha);
                }
            }

            cout << word << '\n';
           // cout << "End of loop before" << cha << '\n';
            file.get(cha);
           // cout << "END OF LOOP CHA" << cha << '\n';
        }
        //file.ignore(256, '>');
//        file.get(cha);
//        cout << cha;
//    file.get(cha);
    }


}

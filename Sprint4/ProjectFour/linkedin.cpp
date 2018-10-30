#include "linkedin.h"

LinkedIn::LinkedIn()
{
    //Wow so empty
}

/*readData parses the data from the input file and
 * puts it into the adjlist
 * @param data is the input file to create the LinkedIn stuff
 */
void LinkedIn::readData(std::string data)
{
    std::ifstream file;
    file.open(data);

    if(!file)
    {
        std::cerr << "Error, file doesn't open" << '\n';
        exit(EXIT_FAILURE);
    }

    int totalWords;
    //Puts the numbe of edges into totalwords
    file >> totalWords;
    file.ignore();

    //Until all words have been read, keep reading
    while(totalWords > 0)
    {
        std::string first;
        std::string second;
        //Get till |

        std::getline(file,first, '|');
        //cout << "First" << first << '\n';
        //Get after |
        std::getline(file,second);
        //file.ignore();
        //cout << "second" << second << '\n';
        list.addEdge(first,second);
        //list.print();
        //cout  << "-----" << '\n';
        totalWords--;
        //file.ignore(200,'\n');
    }

    list.print(); //To test if everything went through
    file.close();
}

/*readCompare reads in the compare data and sends it to a function to
 * find the connections in a vector
 */
void LinkedIn::readCompare(std::string compare)
{
    std::ifstream file;
    file.open(compare);

    if(!file)
    {
        std::cerr << "Error, compare file doesn't open" << '\n';
        exit(EXIT_FAILURE);
    }


}

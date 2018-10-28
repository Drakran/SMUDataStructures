#include "linkedin.h"

LinkedIn::LinkedIn()
{

}

/*readData parses the data from the input file and
 * puts it into the adjlist
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

    //Until all words have been read, keep reading
    while(totalWords > 0)
    {
        std::string first;
        std::string second;
        std::getline(file,first, '|');
        std::getline(file,second);
        list.addEdge(first,second);
        totalWords--;
    }

    list.print();
    file.close();
}

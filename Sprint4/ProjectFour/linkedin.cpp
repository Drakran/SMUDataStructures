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

    //list.print(); //To test if everything went through
    file.close();
}

/*readCompare reads in the compare data and sends it to a function to
 * find the connections in a vector
 * @param the filename of the compare file
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

    int totalWords;
    //Puts the numbe of wanted connections into totalwords
    file >> totalWords;
    file.clear();
    file.ignore();



    while(totalWords > 0)
    {
        std::string first,second;
        std::getline(file,first, '|');
        std::getline(file,second);
        backtrack(first,second);
        totalWords--;
    }
    file.close();
}

/*findConnections will find the connections and store
 * the smallest connection into a vector
 *@param first is the starting point to find the connection
 * @param target is the end of the connection we want
 */
void LinkedIn::backtrack(std::string first, std::string target)
{
    DSvector<Stack<std::string>> combos;
    Stack<std::string> mainStack;
    //Reset all the iters

    //Push Starting Person
    mainStack.push(list.findFirst(first).getIter());
    //std::cerr << list.findFirst(first).getIter();

    //Go until stack is empty(exhaustive search)
    while(!mainStack.isEmpty())
    {
        //If the top of the stack is the target, save the path
        if(mainStack.peek() == target)
        {
            //std::cerr << mainStack.peek();
            combos.put_back(mainStack);
            //std::cerr << combos.getSize();
            //Pop out the latest target so we go back
            mainStack.pop();//Can combine into upper line
            //Steps the list that is on top of the stack
            list.step(mainStack.peek());
        }
        else
        {
            string top = mainStack.peek();
            //std::cerr << mainStack.peek();
            //While the top of the stack's List iterator pointer is in the List(What the pointer is
            //pointing to (the string)) continue
            while(list.findFirst(top).getIterPtr() != nullptr && mainStack.contains((list.findFirst(top)).getIter()))
            {
                string tempTest = list.findFirst(top).getIter();
                list.findFirst(top).next();
                //std::cerr << list.findFirst(top).getIter();
            }
            //The ptr is at head,(which means it looped)
            if((list.findFirst(top)).getIterPtr() != nullptr)
            {
                mainStack.push(list.findFirst(top).getIter());
            }
            else
            {
                list.reset(top);
                mainStack.pop();
                if(mainStack.getSize() !=0)
                {
                    list.step(mainStack.peek());
                }
            }
        }
    }
//    std::cerr << combos.getSize();
//    std::cerr << combos[0].getSize();
    for(int x = 0; x < combos.getSize(); x++)
    {
        //std::cout << combos[x].getSize();
        int size = combos[x].getSize();
        for(int y = 0; y < size; y++)
        {
            std::cout << combos[x].pop();
        }
    }
}

/*inStack checks if the value given is in the stack or not
 */
bool LinkedIn::inStack()
{

}

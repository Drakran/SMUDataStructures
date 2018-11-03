//I do code bc grammar is hard
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
        //Get after |
        std::getline(file,second);
        list.addEdge(first,second);
        totalWords--;
    }

    //list.print(); //Can uncomment to test if everything went through
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

/*outpUt data will put everything nice and peaky like into an outputfile
 *@param the output file name
 */
void LinkedIn::outputData(std::string outputFile)
{
    ofstream out;
    out.open(outputFile);
    //Vector to hold all the names + connections
    DSvector<std::string> connections;
    //Outputs number of connections for each unique name
    for(int x = 0; x < list.getSize(); x++)
    {
        std::string name = list.stepList();
        //For that unique name, go find the connection number to 2nd degree
        int numConnections = findConnections(name);
        std::string numFinal = std::to_string(numConnections);
        //store number of connections and name in our connections vector
        std::string complete = name + " : " + (numFinal);
        connections.put_back(complete);
    }
    //sort vector
    connections.sort(0, connections.getSize());

    //Print out connections numbers
    out << "Number of Connections to 2nd Degree of Seperation" << '\n';
    for(int x = 0; x < connections.getSize(); x++)
    {
        out << connections[x];
        out << '\n';
    }

    //Print out shortest Distance for a pair
    out << '\n' << "Shortest Distance for each pair" << '\n';
    for(int x = 0; x < shortDistance.getSize(); x++)
    {
        out << shortDistance[x] << '\n';
    }
}

/*private function FindConneections will find all
 * connections of that list to a degree of seperation
 * of 2
 * @param string the name to find all connections
 * @return number of connections and secondary connections
 */
int LinkedIn::findConnections(std::string name)
{
    Stack<std::string> connections;
    connections.push(list.findFirst(name).getFirst());

    //Go through everything until end of the name's List
    for(int x = 0; x < list.findFirst(name).getSize() - 1; x++)
    {
        list.step(name);
        //This is the name of the 2nd level of connection(i.e. just
        //the next name in the name's list)
        string nextName = list.findFirst(name).getIter();
        //iterate through the 2nd's name connections
        for(int y = 0; y < list.findFirst(nextName).getSize() ; y++)
        {
            //The name that is next on the nextName's list(start on first)
            string compareName = list.step(nextName);
            //if its not in stack add, if it is dont do anything
            if(!connections.contains(compareName))
            {
                connections.push(compareName);
            }
        }
        //Reset that nextName list so things don't blow up
        list.reset(nextName);
    }
    list.reset(name);
    //Returns the number of unique connections (size of stack - 1(for orgibnal name)
    return connections.getSize() - 1;
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
    list.resetIter(); //Make sure its reset
    //Push Starting Person
    mainStack.push(list.findFirst(first).getIter());
    //std::cerr << list.findFirst(first).getIter();

    //Go until stack is empty(exhaustive search)
    while(!mainStack.isEmpty())
    {
        //If the top of the stack is the target, save the path
        if(mainStack.peek() == target)
        {
            combos.put_back(mainStack);
            //Pop out the latest target so we go back
            mainStack.pop();//Can combine into upper line
            //Steps the list that is on top of the stack
            list.step(mainStack.peek());
        }
        else
        {
            //The name here will be the list we'll be going through
            string top = mainStack.peek();
            //While the top of the stack's List iterator pointer is in the List(What the pointer is
            //pointing to (the string)) go on to the next name(as the previous name is
            //already in the stack and thus can be skipped)
            //Also make sure we haven't reached the end of the list (nullptr)
            //Note it is shortciructed so getIterPtr will check first before getIter
            while(list.findFirst(top).getIterPtr() != nullptr && mainStack.contains((list.findFirst(top)).getIter()))
            {
                list.findFirst(top).next();
            }
            //If we haven't reached the end, push the name on the stack
            if((list.findFirst(top)).getIterPtr() != nullptr)
            {
                mainStack.push(list.findFirst(top).getIter());
            }
            //If we have reached the end, reset the iter and remove the name from the stack
            else
            {
                list.reset(top);
                mainStack.pop();
                //If don't have an empty stack, move the name left one forward so
                //we can continue in the loop
                //If it was empty(i.e. first list was popped out), this would be skipped
                if(mainStack.getSize() !=0)
                {
                    list.step(mainStack.peek());
                }
            }
        }
    }

    //Calls ShortestDistance to find...shortestDistance
    int small = findShortestDistance(combos);

    //Format number inside the vector that holds the string so it
    //is ready for output
    std::string final = first + "|" + target + " " + std::to_string(small);
    shortDistance.put_back(final);
}
/*findShortestDistance compares the stacks and finds
 * which one is the shortest connection distance and
 * returns that
 * @return int the shortest distance
 */
int LinkedIn::findShortestDistance(DSvector<Stack<std::string>> connections)
{
    int smallest = connections[0].getSize(); //Sets value to first size stack
    for(int x = 0; x < connections.getSize(); x++)
    {
        if(connections[x].getSize() < smallest)
        {
            smallest = connections[x].getSize();
        }
    }

    //-1 because the number of connections is the stack size -1 (nodes visited -1)
    return smallest - 1;
}




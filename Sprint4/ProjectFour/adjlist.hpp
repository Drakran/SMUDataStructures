/*
 * The Adjlist is a graph that has elements attatched to each other by edges in aweb like format
 * Essentialy its a linkedlist of linkedlist with each element being the first linkedlist
 * and each element connected to other elements, and all those connections being in
 * the 2nd linkedlist
 *
 * Terry Wang
 *
 * October 21st, 2018
 *
 * Fontenot and the Gang asks, why not recurison?
 */

#ifndef ADJLIST_H
#define ADJLIST_H

#include "linkedlist.hpp"

template<typename T>
class AdjList
{
private:
    LinkedList<LinkedList<T>> data;
    LinkedList<T>& first(T);
public:
    AdjList();
    void addEdge(T, T);
    LinkedList<T>& findFirst(T);
    T step(T);
    T stepList();
    void reset(T);
    void resetIter();
    int getSize();
    //void resetAllIter();
    void print(); //Not really needed
};
#endif // ADJLIST_H

//Default Constructor
template<typename T>
AdjList<T>::AdjList()
{}

/* addEgde inserts an element in the linkedList
 * @param find the element its looking for
 * @param val the connection it will put for find
 */
template<typename T>
void AdjList<T>::addEdge(T find,T val)
{
    bool inserted = false;
    bool insertedSecond = false;
    for(int x = 0; x < data.getSize(); x++)
    {
        //If find first find, pushback val
        if(data[x][0] == find)
        {
            data[x].insertBack(val);
            inserted = true;
        }
        if(data[x][0] == val)
        {
            data[x].insertBack(find);
            insertedSecond = true;
        }
    }
    if(!inserted && !insertedSecond)
    {
        LinkedList<T> temp;//find
        LinkedList<T> temp2;//val
        temp.insertBack(find);
        temp.insertBack(val);
        temp2.insertBack(val);
        temp2.insertBack(find);
        data.insertBack(temp);
        data.insertBack(temp2);
    }
    //If not first not in List already, create the both list for find and val
    else if(!inserted)
    {
        LinkedList<T> temp;//find
        temp.insertBack(find);
        temp.insertBack(val);
        data.insertBack(temp);
    }
    //If there wasn't a 2nd list already, but one for val
    else if(!insertedSecond)
    {
        LinkedList<T> temp;
        temp.insertBack(val);
        temp.insertBack(find);
        data.insertBack(temp);
    }
}

/* find first calls first if its every needed publically (which for test sure)
 * @param val the linkedlist we're looking for
 * @return the first linkedlist in adjlist
 */
template<typename T>
LinkedList<T>& AdjList<T>::findFirst(T val)
{
    return first(val);
}

/*first(private) returns the LinkedList of the first element in the list for a val
 * @param val the linkedlist we're looking for
 * @return the first element in the Adjlist, its refrence but since its a private
 * method it is fine and faster
 */
template<typename T>
LinkedList<T>& AdjList<T>::first(T val)
{
    for(int x = 0; x < data.getSize(); x++)
    {
        if(data[x][0] == val)
        {
            return data[x];
        }
    }
    throw std::logic_error("finding the linkedlist but its not here"); //If not here just don't return anything?
}

/*step iterates through the list iterativly
 * @param which List to step through
 * @return the data at that point in the list
 */
template<typename T>
T AdjList<T>::step(T val)
{
    return first(val).next();
}

/*step iterates through the list iterativly
 * @param which List to step through
 * @return the data at that point in the list
 */
template<typename T>
T AdjList<T>::stepList()
{
    std::string name = data.getIter().getFirst();
    data.next();
    return name;
}

/*Resets the iter for a value
 * @param which List to reset
 */
template<typename T>
void AdjList<T>::reset(T val)
{
    first(val).resetIter();
}


/*resetIter resets the mainList's iter
 */
template<typename T>
void AdjList<T>::resetIter()
{
    data.resetIter();
}

/*getsize...returns the size of the outer linkedlist
 *@return int of size
 */
template<typename T>
int AdjList<T>::getSize()
{
    return data.getSize();
}

/*print is an an example of iteratting
 */
template<typename T>
void AdjList<T>::print()
{
    //For the entire data
    for(int x = 0; x < data.getSize(); x++)
    {
        //For the entire LinkedList where iter is poinintg
        for(int y = 0; y < data.getIter().getSize(); y++)
        {
           //Print everything in that list
           std::cout << step(data.getIter().getFirst());
        }
        //Reset the iter in that list
        reset(data.getIter().getFirst());
        //Move on the next outer list in the data
        data.next();
        std::cout << '\n';
    }
    //put iter back at the beginning
    data.resetIter();
}

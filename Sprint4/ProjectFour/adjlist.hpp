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
    void addEdge(T, T);
    LinkedList<T> findFirst(T);
    T step(T);
    void reset(T);
    void print(); //Not really needed
};
#endif // ADJLIST_H

/* addEgde inserts an element in the linkedList
 * @param find the element its looking for
 * @param val the connection it will put for find
 */
template<typename T>
void AdjList<T>::addEdge(T find,T val)
{
    bool inserted = false;
    for(int x = 0; x < data.getSize(); x++)
    {
        if(data[x][0] == find)
        {
            data[x].insertBack(val);
            inserted = true;
        }
    }
    if(!inserted)
    {
        LinkedList<T> temp;
        temp.insertBack(find);
        temp.insertBack(val);
        data.insertBack(temp);
    }
}

/* find first calls first if its every needed publically (which for test sure)
 * @param val the linkedlist we're looking for
 * @return the first linkedlist in adjlist
 */
template<typename T>
LinkedList<T> AdjList<T>::findFirst(T val)
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

/*Resets the iter for a value
 * @param which List to reset
 */
template<typename T>
void AdjList<T>::reset(T val)
{
    first(val).resetIter();
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

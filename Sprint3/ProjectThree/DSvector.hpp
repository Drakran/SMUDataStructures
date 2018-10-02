/* The DSvector class creates a container much like a vector
 * with dynamically allocated memory that grows to match the number
 * of elements
 *
 * Terry Wang
 *
 * September 21st, 2018
 *
 */

#ifndef DSVECTOR_H
#define DSVECTOR_H

#include <exception>
#include <stdexcept>
#include <algorithm>
#include <utility>

using namespace std;

template<class T>
class DSvector
{
private:
    T* data;
    int size; //numElements
    int capacity;


public:
    DSvector();
    DSvector(int);
    DSvector(const DSvector&);
    ~DSvector();

    DSvector& operator= (const DSvector&);
    T& operator[] (int);

    int getSize();
    int getCapacity();
    T& front();
    T& back();
    bool isEmpty();
    void put_back(T);
    void pop_back();
    void clear();
    T at(const int);
    void swap(int,int);
    void erase(int);
    void sort(const int,const int);
    int partition(const int,const int);

};

//default constructor
template<class T>
DSvector<T>::DSvector()
{
    size = 0;
    capacity = 10; //Default Capacity of 10
    data = new T[10];
}

//Full Constructor
template<class T>
DSvector<T>::DSvector(int initCap)
{
    if(initCap < 0)
    {
        throw logic_error("Size of vector is below zero");
    }
    size = initCap;
    capacity = initCap;
    //'0' terminators put it all in potentially
    data = new T[capacity];

}

//Copy Consustructor
template<class T>
DSvector<T>::DSvector(const DSvector& arg)
{
    this -> size = arg.size;
    this -> capacity = arg.capacity;
    data = new T[capacity];
    for(int x = 0; x < size; x++)
        this -> data[x] = arg.data[x];
}

/* [] operator
 * @param loc is the location needed
 * @return the class type referenced
 */

template<class T>
T& DSvector<T>::operator[](int loc)
{
    if(loc < 0 || loc > size - 1)
        throw out_of_range("[] out of bounds");
    return data[loc];
}

/*Assignment Operator for t1 = t2
 * @param arg is the argument that the data will be taken from
 * @return is vector that was changed to match the argument
 */
template<class T>
DSvector<T>& DSvector<T>::operator=(const DSvector& arg)
{
    //Self-Assignment Precaution
    if(this == &arg)
    {
        return *this;
    }

    //Delete data of THIS if there is data
    if((this -> size) >= 0)
    {
        delete[] data;
    }

    this -> size = arg.size;
    this -> capacity = arg.capacity;
    data = new T[capacity];
    for(int x = 0; x < size ; x++)
        this -> data[x] = arg.data[x];
    return *this;
}

//Deconstructor
template<class T>
DSvector<T>::~DSvector()
{
    delete[] data;
}

//Get Size
template<class T>
int DSvector<T>::getSize()
{
    return size;
}

//Get capacity
template<class T>
int DSvector<T>::getCapacity()
{
    return capacity;
}

//Front - Gets first Element
template<class T>
T& DSvector<T>::front()
{
    if(size > 0)
    {
        return data[0];
    }
    else
        throw logic_error("Front - Vector is empty");
}

//Back - Gets last element
template<class T>
T& DSvector<T>::back()
{
    if(size > 0)
    {
        return data[size - 1];
    }
    else
        throw logic_error("Back - Vector is empty");
}

//IsEmpty
template<class T>
bool DSvector<T>::isEmpty()
{
    if(size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*Put_back inserts an element at the end of the
 * vector. If size is the same as capacity, then
 * the method doubles the vector capacity and stores
 * it in a new memory location before adding
 * the new element at the end of the vector
 * @param val is the value to put in at the end
 */
template<class T>
void DSvector<T>::put_back(T val)
{
    if(capacity == size)
    {
        if(capacity == 0)
            capacity = 1;
        T* temp = new T[capacity * 2]; //Two is standard
        for(int x = 0; x< size; x++)
        {
            temp[x] = data[x];
        }
        capacity*= 2; //Doubles cap of THIS
        delete[] data;
        data = temp;
    }
    data[size++] = val; //Will increment after
}

//Popback
//Destroys the last element in the vector
template<class T>
void DSvector<T>::pop_back()
{
   if(size > 0)
   {
       size--; //'\0' append
   }
   else
   {
       throw logic_error("popback vector is empty");
   }
}

//Clears the vector
template<class T>
void DSvector<T>::clear()
{
    size = 0;
}

//Returns element at location
template<class T>
T DSvector<T>::at(int const loc)
{
    if(loc > size - 1 || loc < 0)
    {
        throw out_of_range("Location out of bounds");
    }
    return data[loc];
}

//Swaps with element position
//Used in the sort
template<class T>
void DSvector<T>::swap(int x, int y)
{
//    T temp = data[x];
//    data[x] = data[y];
//    data[y] = temp;
    std::swap(data[x],data[y]);
}

//Erase Method
template<class T>
void DSvector<T>::erase(int loc)
{
    if(loc > size - 1 || loc < 0)
        throw out_of_range("Erase - out of bounds");
    for(int x = loc; x < size - 1; x++)
    {
        data[x] = data[x+1];
    }
    size--;
}
/*The Sort Function is a Quick Sort Function
 *
 * This is done by gathering the first index and the last index
 * and recursively sorting the elements to the left and right of
 * a chosen pivot (i.e elements <= pivot to left, elements > pivot to right)
 *
 * The pivot is chosen from a median of 3
 *
 * @param left is the first index
 * @param right is the last indes (size - 1)
 */

template<class T>
void DSvector<T>::sort(const int left,const int right)
{
    if(left < right)
    {
        int par = partition(left, right);

        sort(left,par -1);
        sort(par +1, right);
    }

}

/*Two Partition QuickSort
 * @param left is the first index
 * @param right is the last index
 * @return i is the pivot
 */
template<class T>
int DSvector<T>::partition(const int left,const int right)
{

    const int mid = left + (right - left)/2; //Stops the famous overflow bug

    //Swapping elements to sort left,mid,right in order
    //Median swap
    if(data[mid] < data[left])
    {
        std::swap(data[mid],data[left]);
    }
    if(data[right] < data[left])
    {
        std::swap(data[left],data[right]);
    }
    if(data[right] < data[mid])
    {
        std::swap(data[mid],data[right]);
    }

    T pivot = data[mid];

    std::swap(data[mid],data[right]); //move median to last -1
    int i = left;
    int j = right - 1;

    //do comparision till i and j jcross
    while(i <= j)
    {
        //Finds element till one is greater than pivot
        while(data[i] < pivot)
        {
            i++;
        }
        //Finds element till one is less than pivot
        while(data[j] > pivot)
        {
            j--;
        }
        //If i and j havent crossed, swap
        if(i <= j)
        {
            std::swap(data[i],data[j]);
            i++;
            j--;
        }
    }
    //Swap median back to the median position
    std::swap(data[i],data[right]);
    return i; //Returns pivot
}

#endif // DSVECTOR_H

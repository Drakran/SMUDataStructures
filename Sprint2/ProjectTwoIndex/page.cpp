/* The page class holds the number of the page
 * and a vector with all the words associated with that page
 * that were written
 *
 * Terry Wang
 *
 * September 22nd, 2018
 */


#include "page.h"

using namespace std;

//Default Constructor is Empty
Page::Page()
{

}

//Regular Constructor
Page::Page(int pageNum, DSvector<string> allWords)
{
    num = pageNum;
    words = allWords;
}

//getWords returns the word Vector containing all the strings
DSvector<string>& Page::getWords()
{
    return words;
}

//Return page number
int Page::getPageNum()
{
    return num;
}

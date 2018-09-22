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

Page::Page()
{

}

Page::Page(int pageNum, DSvector<string> allWords)
{
    num = pageNum;
    words = allWords;
}

DSvector<string>& Page::getWords()
{
    return words;
}

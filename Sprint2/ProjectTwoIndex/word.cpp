/*
 * The Word Class creates the final word that has the word
 * and the page numbers in a vector of ints ready to be printed out
 *
 * Terry Wang
 *
 * September 22nd, 2018
 */

#include "word.h"

using namespace std;

Word::Word()
{

}

Word::Word(string word, DSvector<int> pages)
{
    this->word = word;
    this->pages = pages;
}

//Gets the vector with the pages Nums
DSvector<int>& Word::getPageNums()
{
    return pages;
}

//Gets the word
string Word::getWord()
{
    return word;
}

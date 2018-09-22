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

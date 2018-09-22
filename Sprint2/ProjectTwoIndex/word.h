/*
 * The Word Class creates the final word that has the word
 * and the page numbers in a vector of ints ready to be printed out
 */

#ifndef WORD_H
#define WORD_H

#include <string>
#include "DSvector.hpp"

class Word
{
private:
    std::string word;
    DSvector<int> pages;

public:
    Word();
    Word(std::string, DSvector<int>);
};

#endif // WORD_H

/*
 * The word structure has both the string word and
 * length of the words. This is used to make it
 * very easier to sort by > and <
 *
 * Terry Wang
 *
 */

#ifndef WORD_H
#define WORD_H

#include <string>
#include <tuple>

struct Word
{
    std::string word;
    int length;

    Word();
    Word(std::string, int);
    bool operator <(const Word&);
    bool operator >(const Word&);
};

#endif // WORD_H

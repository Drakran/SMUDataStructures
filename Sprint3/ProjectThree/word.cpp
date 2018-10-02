/*
 * The word structure has both the string word and
 * length of the words. This is used to make it
 * very easier to sort by > and <
 *
 * Terry Wang
 *
 * October 2nd, 2018
 */

#include "word.h"

using namespace std;

//Default Constructor
Word::Word()
{

}

//Good Constructor
Word::Word(string word, int len)
{
    this->word = word;
    this->length = len;
}

/*< Operator
 * Using ties basically compares length to length and word to word
 */
bool Word::operator <(const Word& arg)
{
    return tie(length,word) < tie(arg.length, arg.word);
}

/*> Operator
 * Using ties basically compares length to length and word to word
 */
bool Word::operator >(const Word& arg)
{
    return tie(length,word) > tie(arg.length, arg.word);
}

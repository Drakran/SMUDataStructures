#include "word.h"

using namespace std;

Word::Word()
{

}

Word::Word(string word, int len)
{
    this->word = word;
    this->length = len;
}

bool Word::operator <(const Word& arg)
{
    return tie(length,word) < tie(arg.length, arg.word);
}

bool Word::operator >(const Word& arg)
{
    return tie(length,word) > tie(arg.length, arg.word);
}

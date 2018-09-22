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

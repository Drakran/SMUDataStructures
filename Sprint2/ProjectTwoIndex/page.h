#ifndef PAGE_H
#define PAGE_H

#include <string>
#include "DSvector.hpp"

class Page
{
private:
    int num;
    DSvector<std::string> words;
public:
    Page(int, DSvector<std::string>);
    DSvector<std::string>& getWords();
};

#endif // PAGE_H

#ifndef PAGE_H
#define PAGE_H

#include <string>
#include "DSvector.hpp"

class Page
{
private:
    std::string num;
    DSvector<std::string> words;
public:
    Page(std::string, DSvector<std::string>);
};

#endif // PAGE_H

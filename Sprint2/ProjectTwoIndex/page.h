/* The page class holds the number of the page
 * and a vector with all the words associated with that page
 * that were written
 *
 * Terry Wang
 *
 * September 22nd, 2018
 */

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
    Page();
    Page(int, DSvector<std::string>);
    DSvector<std::string>& getWords();
    int getPageNum();
};

#endif // PAGE_H

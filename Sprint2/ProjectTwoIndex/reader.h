/* The reader class reads in the sample index file and
 * pharses out for eventual processing into the
 * page vector.
 *
 * The main method involved in this
 * is the getData method that gets the data and
 * pharses it out (though it could've probably been split but
 * this is a future remark for future me - like either split
 * it into another class or another method)
 *
 * Terry Wang
 *
 * September 21st, 2018
 */

#ifndef READER_H
#define READER_H

#include "page.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

class Reader
{
private:
    std::string input;
    std::string output;
public:
    Reader(std::string, std::string);
    void getData(DSvector<Page>&);
};

#endif // READER_H

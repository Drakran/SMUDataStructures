
#include <iostream>
#include <DSvector.hpp>


using namespace std;

int main()
{
    DSvector<int> test;
    for(int x = 0; x < 30; x++)
    {
        test.put_back(-x);
    }
    //cerr << test.getSize();
    //cout << test[0];
    test.sort(0,test.getSize()-1);
    for(int x = 0; x < test.getSize(); x++)
    {
        cerr << test[x] << '\n';
    }
    //cout << "Hello World!" << endl;
    return 0;
}

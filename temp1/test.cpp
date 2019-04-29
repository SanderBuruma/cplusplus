#include <iostream>
#include "test.h"
using namespace std;

test::test()
{
    cout << "Up!" << endl;
}

test::~test()
{
    cout << "Down!" << endl;
}

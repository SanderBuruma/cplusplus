#include <iostream>

using namespace std;

template <class bucky>
bucky addCrap(bucky a, bucky b){
    return a+b;
}

int main()
{
    double x=7.5, y=6, z;
    cout << addCrap(x, y) << endl;
    return 0;
}

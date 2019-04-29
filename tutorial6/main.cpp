#include <iostream>

using namespace std;

template <class A, class B>
A smaller (A a, B b){
    return (a<b?a:b);
}

int main()
{
    int x = 89;
    double y = 56.78;
    cout << smaller(x, y) << endl;
    return 0;
}

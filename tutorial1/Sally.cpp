#include "Sally.h"
#include <iostream>
using namespace std;

Sally::Sally()
{
    num = 1;
}
Sally::Sally(int a)
{
    num = a;
}

Sally Sally::operator+(Sally aso){
    Sally brandNew;
    brandNew.num = num + aso.num;
    return(brandNew);
}

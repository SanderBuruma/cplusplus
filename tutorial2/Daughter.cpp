#include "Mother.h"
#include "Daughter.h"
#include <iostream>
using namespace std;

Daughter::Daughter()
{
    cout << "I am the daughter constructor" << endl;
}
Daughter::~Daughter()
{
    cout << "I am the daughter de constructor" << endl;
}

void Daughter::doSomething(){

}

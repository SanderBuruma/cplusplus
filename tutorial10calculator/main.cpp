#include <iostream>

using namespace std;

int main()
{

    try{

        int num1;
        cout << "Enter first number: \n";
        cin >> num1;

        int num2;
        cout << "Enter second number: \n";
        cin >> num2;

        if(num2 == 0){
            throw 0;
        }

        cout << num1/num2 << endl;

    }catch (int x){
        cout << "You can't divide by " << x << endl;
    }

}

#include <iostream>
#include <string>
using namespace std;

int main()
{

    //string bucky;
    //getline(cin, bucky);
    //cout << "the string I entered is: " << bucky << endl;

    string s1("apples ");
    string s2;
    string s3;

    s2 = s1;
    s3.assign(s1);
    cout << s1.at(3) << endl;
    for (int x=0 ; x<s1.length(); x++){
        cout << s1.at(x);
    }

    cout << endl << s1.substr(1,2) << endl;
    s2 = "beans ";
    cout << s1 << " " << s2 << endl;
    s1.swap(s2);
    cout << s1 << " " << s2 << endl;

    s1 = "Hi, my name is Bucky and I love bacon and ham!";
    cout << s1 << endl;
    s1.replace(15, 5, "Samuel Jackson");
    cout << s1 << endl;

}

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream buckysFile("beefjerky.txt");

    if(buckysFile.is_open()){
        cout << "File is open!\n";
    } else {
        cout << "Error, File is NOT open!\n";
    }

    buckysFile << "O, I love beef!\n";
    buckysFile.close();
}

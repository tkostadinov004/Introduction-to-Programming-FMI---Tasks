#include <iostream>
#include <cmath>;
using namespace std;

int main()
{
    char letter;
    cin >> letter;

    if (letter >= 'a' && letter <= 'z') {
        cout << "Lower case letter" << endl;
        cout << "Its equivalent upper case letter is: " << (char)(letter - 32);
    }
    else if (letter >= 'A' && letter <= 'Z') {
        cout << "Upper case letter";
        cout << "Its equivalent lower case letter is: " << (char)(letter + 32);
    }
    else {
        cout << "The character is NOT a letter";
    }
}
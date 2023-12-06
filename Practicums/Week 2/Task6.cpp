#include <iostream>
#include <cmath>;
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if (x == 0 || y == 0) {
        cout << "On axis";
    }
    else if (x > 0) {
        cout << (y > 0 ? "First" : "Fourth");
    }
    else {
        cout << (y > 0 ? "Second" : "Third");
    }
}
#include <iostream>
#include <cmath>;
using namespace std;

int main()
{
    int x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

    bool isInBounds = ((y <= y2 && y >= y1) || (y <= y1 && y >= y2)) && ((x <= x2 && x >= x1) || (x <= x1 && x >= x2));
    if ((x == x1 || x == x2 || y == y1 || y == y2) && isInBounds) {
        cout << "Border";
    }
    else if (isInBounds) {
        cout << "Inside";
    }
    else {
        cout << "Outside";
    }
}
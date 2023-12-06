#include <iostream>
#include <cmath>;
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    bool isValid = a < b + c && b < a + c && c < a + b;
    cout << (isValid ? "YES, you can make a triangle out of this :)" : "NO, you can't make a triangle out of this :(");
}
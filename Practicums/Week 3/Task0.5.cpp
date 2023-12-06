#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;

    cin >> n;
    for (double i = n; i > 0; i -= 0.5)
    {
        cout << i << " ";
    }
}
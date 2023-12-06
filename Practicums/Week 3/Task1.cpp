#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int fact = 1;
    for (int i = n; i >= 1; i--)
    {
        fact *= i;
    }
    cout << fact;
}
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double number;
    int power;
    cin >> number >> power;

    if (number == 0 && power == 0)
    {
        cout << "unknown";
    }
    else
    {
        bool isPowerNegative = power < 0;
        if (isPowerNegative)
        {
            power *= -1;
        }

        double result = 1;
        for (int i = power - 1; i >= 0; i--)
        {
            result *= number;
        }
        cout << (isPowerNegative ? 1 / result : result);
    }
}
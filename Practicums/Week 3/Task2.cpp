#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int sum = 0;

    int n = 0;
    do
    {
        sum += n;
        cin >> n;
    } while (n != 0);

    cout << sum;
}
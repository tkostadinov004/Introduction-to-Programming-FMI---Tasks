#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool isPrime = true;

    int root = sqrt(n);
    for (int i = 2; i <= root; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    cout << (isPrime && n >= 2 ? "YES" : "NO");
}
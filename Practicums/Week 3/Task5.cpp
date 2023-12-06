#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int morePrev = 1, prev = 1;

    for (int i = 2; i < n; i++)
    {
        prev += morePrev;
        morePrev = prev - morePrev;
    }
    cout << prev;
}
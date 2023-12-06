#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {
            for (int j = 0; j < n; j++)
            {
                cout << '*';
            }
            cout << endl;
            continue;
        }

        if (i < 2) {
            for (int j = 0; j < n; j++)
            {
                if (j == 0 || j == n - 1) {
                    cout << '*';
                }
                else {
                    cout << ' ';
                }
            }
        }
        else {
            for (int j = 0; j < i; j++)
            {
                cout << '*';
            }
            for (int j = i; j < n - 1; j++) {
                cout << ' ';
            }
            cout << '*';
        }
        cout << endl;
    }
}
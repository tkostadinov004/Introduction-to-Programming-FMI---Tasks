#include <iostream>
using namespace std;

bool isInteresting(unsigned n)
{
    if (n < 10)
    {
        return true;
    }

    int first = n % 10;
    n /= 10;
    while (n > 0)
    {
        int second = n % 10;
        if (second > first)
        {
            return false;
        }
        n /= 10;
        first = second;
    }
    return true;
}
void printResult(const int arr[], unsigned len)
{
    for (int i = 0; i < len; i++)
    {
        cout << (isInteresting(arr[i]) ? "YES" : "NO") << endl;
    }
}
int main()
{

}
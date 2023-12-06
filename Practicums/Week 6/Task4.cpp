#include <iostream>
using namespace std;

bool isMirrored(const int arr[], unsigned len)
{
    for (int i = 0; i < len / 2; i++)
    {
        if (arr[i] != arr[len - 1 - i])
        {
            return false;
        }
    }
    return true;
}
int main()
{

}
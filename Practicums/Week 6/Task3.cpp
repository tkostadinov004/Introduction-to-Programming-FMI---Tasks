#include <iostream>
using namespace std;

int getOccurrences(const int arr[], unsigned len, int num)
{
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == num)
        {
            count++;
        }
    }
    return count;
}
void printDuplicates(const int arr[], unsigned len, int num)
{
    int occs = getOccurrences(arr, len, num);
    cout << occs << " ";

    if (occs > 0)
    {
        cout << "The positions are: ";
        for (int i = 0; i < len; i++)
        {
            if (arr[i] == num)
            {
                cout << i << " ";
            }
        }
    }
    else
    {
        cout << "The number isn't in the array";
    }
}
int main()
{

}
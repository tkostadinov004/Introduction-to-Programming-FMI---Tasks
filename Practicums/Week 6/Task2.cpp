#include <iostream>
using namespace std;

int min(const int arr[], unsigned len, int skipIndex) 
{
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] < min)
        {
            if (skipIndex > -1 && arr[i] > arr[skipIndex])
            {
                min = arr[i];
                minIndex = i;
                continue;
            }
            else if (skipIndex == -1)
            {
                min = arr[i];
                minIndex = i;
            }
        }
    }
    return minIndex;
}
int max(const int arr[], unsigned len, int skipIndex) 
{
    int max = INT_MIN;
    int maxIndex = -1;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > max)
        {
            if (skipIndex > -1 && arr[i] < arr[skipIndex])
            {
                max = arr[i];
                maxIndex = i;
                continue;
            }
            else if (skipIndex == -1)
            {
                max = arr[i];
                maxIndex = i;
            }
        }
    }
    return maxIndex;
}
void printMinMaxOutput(const int arr[], unsigned len)
{
    int minIndex = min(arr, len, -1);
    int maxIndex = max(arr, len, -1);
    cout << "Min " << arr[minIndex] << " Max " << arr[maxIndex] << " Second Min " << arr[min(arr, len, minIndex)] << " Second Max " << arr[max(arr, len, maxIndex)] << endl;
}
int main()
{

}
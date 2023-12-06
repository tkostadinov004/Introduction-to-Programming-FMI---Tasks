#include <iostream>
using namespace std;

void inputArray(double arr[], unsigned n, const unsigned MAX_LENGTH)
{
    if (n <= MAX_LENGTH) 
    {
        for (int i = 0; i < n; i++)
        {
            double num;
            cin >> num;
            arr[i] = num;
        }
    }
}
void inputArray(int arr[], unsigned n, const unsigned MAX_LENGTH)
{
    if (n <= MAX_LENGTH) 
    {
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr[i] = num;
        }
    }
}
void printArray(const double arr[], unsigned len) 
{
    cout << '[';
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << (i < len - 1 ? ", " : "");
    }
    cout << ']';
}
double getAverage(const double arr[], unsigned len)
{
    double sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    return sum / len;
}
void getOutput(const double arr[], unsigned len)
{
    printArray(arr, len);
    cout << " " << getAverage(arr, len) << endl;
}
int main()
{

}
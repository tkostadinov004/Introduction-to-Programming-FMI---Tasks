#include <iostream>
using namespace std;

unsigned getUnique(const unsigned arr[], size_t length)
{
    unsigned result = 0;
    for (int i = 0; i < length; i++)
    {
        result ^= arr[i];
    }
    return result;
}
int main()
{

}
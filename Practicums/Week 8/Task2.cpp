#include <iostream>
using namespace std;

unsigned getSetBitsCount(unsigned n)
{
    unsigned count = 0;
    while (n > 0)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}
int main()
{

}
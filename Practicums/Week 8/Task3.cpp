#include <iostream>
using namespace std;

unsigned getFirstSetBitPosition(unsigned n)
{
    int pos = 0;
    while ((n & 1) != 1)
    {
        n >>= 1;
        pos++;
    }
    return pos;
}
unsigned flipFirstSetBit(unsigned n)
{
    return n ^ (1 << getFirstSetBitPosition(n));
}
int main()
{

}
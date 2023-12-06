#include <iostream>
using namespace std;

unsigned replaceBits(unsigned a, unsigned b, unsigned i, unsigned j)
{
    unsigned mask = (1 << (j - i + 1)) - 1;
    return ((b & mask) << i) ^ a;
}
int main()
{

}
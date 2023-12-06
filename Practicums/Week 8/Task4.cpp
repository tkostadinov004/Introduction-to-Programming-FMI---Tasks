#include <iostream>
using namespace std;

unsigned getLastKBits(unsigned n, unsigned k)
{
    return n & ((1 << k) - 1);
}
int main()
{

}
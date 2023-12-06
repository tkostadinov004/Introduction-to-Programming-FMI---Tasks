#include <iostream>
using namespace std;

bool isEven(unsigned n)
{
    return !(n & 1);
}
bool isPartOfN(unsigned n, unsigned k)
{
    if (k == 0)
    {
        return n == 0 || isEven(n);
    }

    while (n > 0)
    {
        if ((n & k) == k)
        {
            return true;
        }
        n >>= 1;
    }
    return false;
}
int main()
{

}
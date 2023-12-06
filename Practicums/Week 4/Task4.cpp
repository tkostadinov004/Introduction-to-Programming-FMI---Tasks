#include <iostream>
using namespace std;

int digitCount(int n, int digit)
{
	int count = 0;
	while (n > 0)
	{
		count += (n % 10 == digit);
		n /= 10;
	}
	return count;
}
int main()
{

}
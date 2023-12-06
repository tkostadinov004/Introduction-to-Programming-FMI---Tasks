#include <iostream>
using namespace std;

bool isPerfect(int n)
{
	int divisorsSum = 1;
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			divisorsSum += i;
		}
	}
	return n == divisorsSum;
}
int main()
{

}
#include <iostream>
using namespace std;

bool isPrime(int n)
{
	double root = sqrt(n);
	for (int i = 2; i <= root; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
bool areConjoinedPrimes(int a, int b)
{
	return a - b == -2 && isPrime(a) && isPrime(b);
}
int main()
{

}
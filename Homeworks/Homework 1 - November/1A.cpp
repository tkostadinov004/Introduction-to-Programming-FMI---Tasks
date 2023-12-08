#include <iostream>
using namespace std;

unsigned removeDigit(unsigned n, unsigned exponentOf10)
{
	return (n / (exponentOf10 * 10)) * exponentOf10 + (n % exponentOf10);
}
bool isPossible(unsigned n, unsigned tryN) 
{
	if (n / 10 == 0 && tryN == 0) 
	{
		return false;
	}

	unsigned exponentOf10 = 1;
	while (exponentOf10 <= n)
	{
		if (removeDigit(n, exponentOf10) == tryN) 
		{
			return true;
		}
		exponentOf10 *= 10;
	}
	return false;
}
int main()
{
	unsigned n, tryN;
	cin >> n;
	cin >> tryN;

	cout << (isPossible(n, tryN) ? "Yes" : "No") << endl;
}


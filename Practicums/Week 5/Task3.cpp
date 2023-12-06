#include <iostream>
using namespace std;

bool areDigitsEqual(unsigned n) 
{
	if (n < 10) 
	{
		return true;
	}
	int prevDigit = n % 10;
	n /= 10;
	while (n > 0) 
	{
		int currentDigit = n % 10;
		if (currentDigit != prevDigit) 
		{
			return false;
		}
		prevDigit = currentDigit;
		n /= 10;
	}
	return true;
}
int main()
{

}
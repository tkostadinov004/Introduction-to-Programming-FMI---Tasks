#include <iostream>
using namespace std;

unsigned concatDigitAtBack(unsigned n, unsigned digit)
{
	return n * 10 + digit;
}

unsigned countDigitOccurences(unsigned n, unsigned digit)
{
	if (digit == 0 && n == 0)
		return 1;

	unsigned count = 0;
	while (n != 0)
	{
		int lastDigit = n % 10;
		if (lastDigit == digit)
			count++;
		n /= 10;
	}
	return count;
}

unsigned concatCountTimesDigit(unsigned a, unsigned digit, unsigned count)
{
	unsigned result = a;
	for (int i = 0; i < count; i++)
		result = concatDigitAtBack(result, digit);
	return result;
}

unsigned sortNumberDescending(unsigned n)
{
	unsigned result = 0;
	for (int i = 9; i >= 0; i--)
	{
		unsigned count = countDigitOccurences(n, i);
		result = concatCountTimesDigit(result, i, count);
	}
	return result;
}
unsigned removeZeroesAtEnd(int n) 
{
	if (n < 10) {
		return n;
	}

	while (n % 10 == 0) {
		n /= 10;
	}
	return n;
}
unsigned reverse(int n) 
{
	int result = 0;
	while (n > 0) {
		(result *= 10) += n % 10;
		n /= 10;
	}
	return result;
}
bool areDigitsSorted(int n) 
{
	return removeZeroesAtEnd(n) == sortNumberDescending(removeZeroesAtEnd(n)) || removeZeroesAtEnd(n) == reverse(sortNumberDescending(removeZeroesAtEnd(n)));
}
int main()
{

}
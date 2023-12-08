#include <iostream>
using namespace std;

void fillArray(unsigned arr[], unsigned length, unsigned value)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = value;
	}
}
bool doTwoNumbersHaveTheSameDigits(unsigned a, unsigned b)
{
	unsigned digitsOfA[10], digitsOfB[10];
	fillArray(digitsOfA, 10, 0);
	fillArray(digitsOfB, 10, 0);
	while (a > 0)
	{
		digitsOfA[a % 10]++;
		digitsOfB[b % 10]++;
		a /= 10;
		b /= 10;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (digitsOfA[i] != digitsOfB[i])
		{
			return false;
		}
	}
	return true;
}
void printPermutations(unsigned n)
{
	for (int i = 1000; i < 10000; i++)
	{
		if (doTwoNumbersHaveTheSameDigits(n, i))
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

int main()
{
	unsigned n;
	cin >> n;
	printPermutations(n);
}


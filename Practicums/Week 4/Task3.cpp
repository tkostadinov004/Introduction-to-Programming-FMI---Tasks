#include <iostream>
using namespace std;

unsigned int absoluteValue(int n)
{
	return n < 0 ? n * (-1) : n;
}
double power(double n, int pow)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

	bool isNegative = pow < 0;
	pow = absoluteValue(pow);

	double result = 1;
	for (int i = pow; i > 0; i--)
	{
		result *= n;
	}
	return isNegative ? 1 / result : result;
}
double fmin(double a, double b)
{
	return a < b ? a : b;
}
double fmax(double a, double b)
{
	return  a > b ? a : b;
}
double minOfThree(double a, double b, double c)
{
	return fmin(fmin(a, b), c);
}
double maxOfThree(double a, double b, double c)
{
	return fmax(fmax(a, b), c);
}
bool isUpper(char c)
{
	return c >= 'A' && c <= 'Z';
}
bool isLower(char c)
{
	return c >= 'a' && c <= 'z';
}
bool isLetter(char c)
{
	return isUpper(c) || isLower(c);
}
bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}
int main()
{

}
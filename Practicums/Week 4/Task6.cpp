#include <iostream>
using namespace std;

bool isPalindrome(int n)
{
	int left = 1;
	int temp = n;
	while (temp >= 10)
	{
		left *= 10;
		temp /= 10;
	}

	int right = 1;
	while (left > right)
	{
		if ((n / left) % 10 != (n / right) % 10)
		{
			return false;
		}
		left /= 10;
		right *= 10;
	}
	return true;
}
int main()
{

}
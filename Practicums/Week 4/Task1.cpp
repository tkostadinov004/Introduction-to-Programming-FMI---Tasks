#include <iostream>
using namespace std;

int fib(int n)
{
	if (n == 0)
	{
		return 0;
	}

	int morePrev = 1;
	int prev = 1;
	for (int i = 2; i <= n - 1; i++)
	{
		int swap = morePrev;
		morePrev = prev;
		prev = swap;

		prev += morePrev;
	}
	return prev;
}
int main()
{
	cout << fib(5);
}
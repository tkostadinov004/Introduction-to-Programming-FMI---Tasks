#include <iostream>
using namespace std;

void fibonacciLine(int n)
{
	if (n == 0)
	{
		return;
	}

	int morePrev = 0;
	int prev = 1;
	for (int i = 2; i <= n + 1; i++)
	{
		cout << morePrev << " ";
		int swap = morePrev;
		morePrev = prev;
		prev = swap;

		prev += morePrev;

	}
}
int main()
{

}
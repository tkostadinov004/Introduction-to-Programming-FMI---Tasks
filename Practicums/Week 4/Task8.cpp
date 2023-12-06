#include <iostream>
using namespace std;

int removeHundreds(int n)
{
	return 100 * ((n / 1000) % 10) + 10 * ((n / 10) % 10) + n % 10;
}
void printElevens(int m, int n)
{
	if (m > n)
	{
		cout << "Invalid input!";
		return;
	}

	for (int i = m; i <= n; i++)
	{
		if (removeHundreds(i) % 11 == 0)
		{
			cout << i << " ";
		}
	}
}
int main()
{

}
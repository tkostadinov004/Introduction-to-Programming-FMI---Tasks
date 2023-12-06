#include <iostream>
using namespace std;

void printElement(int k, char symb)
{
	for (int i = 0; i < k; i++)
	{
		cout << symb;
	}
}
void protons(int n)
{
	for (int i = 0; i < n; i++)
	{
		printElement(i, '-');
		printElement(n - i, '+');
		cout << endl;
	}
}
int main()
{
	protons(5);
}
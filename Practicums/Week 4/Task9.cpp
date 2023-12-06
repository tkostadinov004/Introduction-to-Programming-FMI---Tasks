#include <iostream>
using namespace std;

void printLineWithArg(int count, char c)
{
	for (int i = 0; i < count; i++)
	{
		cout << c;
	}
}
void printDiamond(int n)
{
	for (int i = 1; i <= n + 4; i += 2)
	{
		printLineWithArg((n + 4 - i) / 2, ' ');
		printLineWithArg(i, '*');
		printLineWithArg((n + 4 - i) / 2, ' ');
		cout << endl;
	}
	for (int i = n + 2; i >= 1; i -= 2)
	{
		printLineWithArg((n + 4 - i) / 2, ' ');
		printLineWithArg(i, '*');
		printLineWithArg((n + 4 - i) / 2, ' ');
		cout << endl;
	}
}
int main()
{

}
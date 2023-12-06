#include <iostream>
#include <cmath>;
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a = n % 10;
	int b, c, d;
	b = (n /= 10) % 10;
	c = (n /= 10) % 10;
	d = (n /= 10) % 10;

	bool isUnique = (a != b && b != c && c != d && a != d);
	cout << (isUnique ? "YES, all the numbers are different!" : "NO, not all numbers are different!");
}
#include <iostream>
using namespace std;

bool isLowercase(char c)
{
	return c >= 'a' && c <= 'z';
}
char capitalize(char c) {
	if (!isLowercase(c)) 
	{
		return c;
	}

	return c - 32;
}
int main()
{

}
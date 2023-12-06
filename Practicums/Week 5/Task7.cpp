#include <iostream>
using namespace std;

bool isDigit(char c) 
{
	return c >= '0' && c <= '9';
}
int convertToInt(char c) 
{
	return isDigit(c) ? c - '0' : -1;
}
int main()
{

}
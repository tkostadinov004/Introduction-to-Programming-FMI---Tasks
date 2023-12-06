#include <iostream>
using namespace std;

double getLinearEqRoots(double a, double b) 
{
	if (a == 0 && b == 0) 
	{
		return INFINITY;
	}
	else if (a == 0) 
	{
		return NAN;
	}

	return (-b) / a;
}
int main()
{

}
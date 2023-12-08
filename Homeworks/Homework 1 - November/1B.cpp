#include <iostream>
using namespace std;

int getElementIndex(int searchElement, int start, unsigned end, const int a[], const int b[])
{
	for (int j = start; j < end; j++)
	{
		if (a[j] == searchElement) 
		{
			return j + 1;
		}
	}
	return -1;
}
bool isPossible(const int a[], size_t lengthOfA, const int b[], size_t lengthOfB)
{
	if (lengthOfA <= lengthOfB) 
	{
		return false;
	}

	int currentStartIndex = 0;
	for (int i = 0; i < lengthOfB; i++)
	{
		currentStartIndex = getElementIndex(b[i], currentStartIndex, lengthOfA, a, b);

		if (currentStartIndex == -1) 
		{
			return false;
		}
	}
	return true;
}
int main()
{

}


#include <iostream>
using namespace std;

bool fillAndCheckArray(int* arr, size_t size)
{
	if (!arr)
	{
		return false;
	}

	for (size_t i = 2; i < size + 2; i++)
	{
		cin >> arr[i];
		if (i > 2 && arr[i] < arr[i - 1])
		{
			return false;
		}
	}
	return true;
}
void printArray(const int* arr, size_t size)
{
	if (!arr)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << *(arr++) << " ";
	}
}
int getIndexOfFirstNonEmpty(int** arrays, size_t arraysCount)
{
	if (!arrays)
	{
		return -1;
	}

	for (size_t i = 0; i < arraysCount; i++)
	{
		if (arrays[i][1] < arrays[i][0] + 2)
		{
			return i;
		}
	}
	return -1;
}
int getMinArrayIndex(int** arrays, size_t arraysCount)
{
	if (!arrays)
	{
		return -1;
	}

	int minIndex = getIndexOfFirstNonEmpty(arrays, arraysCount);
	for (size_t i = minIndex; i < arraysCount; i++)
	{
		if (arrays[i][1] < arrays[i][0] + 2 && arrays[i][arrays[i][1]] < arrays[minIndex][arrays[minIndex][1]])
		{
			minIndex = i;
		}
	}
	return minIndex;
}
int* sortArrays(int** arrays, size_t arraysCount, size_t totalSize)
{
	if (!arrays)
	{
		return nullptr;
	}

	int* sorted = new int[totalSize];

	unsigned index = 0;
	while (index < totalSize)
	{
		int indexOfMin = getMinArrayIndex(arrays, arraysCount);
		if (indexOfMin == -1)
		{
			break;
		}
		sorted[index++] = arrays[indexOfMin][arrays[indexOfMin][1]++];
	}
	return sorted;
}
int** initializeArrays(size_t arraysCount, bool& areArraysSorted, size_t& totalSize)
{
	int** arrays = new int* [arraysCount];

	for (size_t i = 0; i < arraysCount; i++)
	{
		size_t currentSize;
		cin >> currentSize;
		int* currentArray = new int[currentSize + 2];
		currentArray[0] = currentSize; // the element at index 0 shows the length of the array
		currentArray[1] = 2; // the element at index 1 shows the current index of the array (used in sorting)

		if (!fillAndCheckArray(currentArray, currentSize))
		{
			areArraysSorted = false;
		}
		totalSize += currentSize;
		arrays[i] = currentArray;
	}

	return arrays;
}
void clearMemory(int** arr, size_t size)
{
	if (!arr)
	{
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
int main()
{
	size_t arraysCount;
	cin >> arraysCount;

	bool areArraysSorted = true;
	size_t totalSize = 0;
	int** arrays = initializeArrays(arraysCount, areArraysSorted, totalSize);

	if (areArraysSorted)
	{
		int* sorted = sortArrays(arrays, arraysCount, totalSize);
		printArray(sorted, totalSize);
		delete[] sorted;
	}
	else
	{
		cout << "All arrays should be sorted.";
	}
	clearMemory(arrays, arraysCount);
}
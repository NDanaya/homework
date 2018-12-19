#include <iostream>

using namespace std;

int nextSmallerThan(int);
void nextSmallerThanTests();
void countDigits(int, int *);
bool isArrayEqual(int *, int *, int);
void createArrayOfZeros(int *, int);

const int N = 10;

int main()
{
	nextSmallerThanTests();

	system("pause");
	return 0;
}

int nextSmallerThan(int number)
{
	int originalArray[N];
	int newArray[N];

	createArrayOfZeros(originalArray, N);
	countDigits(number, originalArray);

	for (int i = number - 1; i > 0; i--)
	{
		countDigits(i, newArray);

		if (isArrayEqual(originalArray, newArray, N))
		{
			return i;
		}
	}

	return -1;
}

bool isArrayEqual(int* firstArray, int* secondArray, int size)
{
	for (int j = 0; j < size; j++)
	{
		if (firstArray[j] != secondArray[j])
		{
			return false;
		}
	}

	return true;
}

void createArrayOfZeros(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = 0;
	}
}

void countDigits(int number, int* array)
{
	createArrayOfZeros(array, N);

	while (number > 0)
	{
		int digit = number % 10;
		array[digit] += 1;
		number /= 10;
	}

}

void nextSmallerThanTests()
{
	cout << (nextSmallerThan(21) == 12) << endl;
	cout << (nextSmallerThan(531) == 513) << endl;
	cout << (nextSmallerThan(2071) == 2017) << endl;
	cout << (nextSmallerThan(9) == -1) << endl;
	cout << (nextSmallerThan(111) == -1) << endl;
	cout << (nextSmallerThan(135) == -1) << endl;
	cout << (nextSmallerThan(1027) == -1) << endl;
	cout << (nextSmallerThan(-100) == -1) << endl;

	cout << (nextSmallerThan(364) == 346) << endl;
	cout << (nextSmallerThan(9051) == 9015) << endl;
	cout << (nextSmallerThan(534) == 453) << endl;
	cout << (nextSmallerThan(4) == -1) << endl;
	cout << (nextSmallerThan(383) == 338) << endl;
	cout << (nextSmallerThan(222) == -1) << endl;
	cout << (nextSmallerThan(123) == -1) << endl;
	cout << (nextSmallerThan(20) == -1) << endl;
}

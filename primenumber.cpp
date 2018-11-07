#include <iostream>

using namespace std;

bool IsPrimeNumber(int number);

int main()
{
	cout << "Please enter a number:\n";

	long long number;
	cin >> number;
	system("cls");

	IsPrimeNumber(number);

	if (IsPrimeNumber(number))
	{
		cout << "prime number\n";
	}

	else
	{
		cout << " not prime number\n";
	}

	system("pause");
	return 0;
}

bool IsPrimeNumber(int number)
{
	if (number <= 1)
	{
		return false;
	}

	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{ 
			return false;
			break;
		}
	}
	return true;
}
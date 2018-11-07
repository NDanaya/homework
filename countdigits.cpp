#include <iostream>

using namespace std;

void CountDigits(long long number);
void FindMaxMinDigit(long long number);

int main()
{
	cout << "Please enter a number:\n";

	long long number;
	cin >> number;
	system("cls");

	CountDigits(number);
	FindMaxMinDigit(number);

	system("pause");
	return 0;
}

void CountDigits(long long number)
{
	long long value = number > 0 ? number : -number;
	int count = 0;

	while (value != 0)
	{
		count++;
		value /= 10;
	}

	cout << "Number of digits: " << count << endl;
}

void FindMaxMinDigit(long long number)
{
	long long value = number > 0 ? number : -number;
	int maxdigit = 0, mindigit = 9, count = 1;

	for (; value; count++)
	{
		mindigit = value % 10 < mindigit ? value % 10 : mindigit;
		maxdigit = value % 10 > maxdigit ? value % 10 : maxdigit;
		value /= 10;
	}

	cout << "Maximum digit: " << maxdigit << "," << "Minimum digit: " << mindigit << endl;
}
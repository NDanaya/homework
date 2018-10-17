#include <iostream>; 
using namespace std;

int InputTask();
double result;
int task;
const double pi = 3.14159265;


int main()
{
	char esc = 'y';

	while (esc == 'y' || esc == 'Y')
	{

		int task = InputTask();

		cout << "press y or Y to continue" << endl;
		cin >> esc;
	}

	return 0;
}


double task1(int n)
{
	for (int i = 1; i <= n; i++)
	{
		result += 1. / i;
	}

	return result;
}

double task2(int n)
{
	result = pow(2, n);

	return result;
}

double task3(int n)
{
	result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= (1 + (1 / (pow(i, 2))));
	}

	return result;
}

double task4(int n)
{
	for (int i = 1; i <= n; i++)
	{
		result += pow(-1, i + 1) / (i*(i + 1));
	}

	return result;
}

double task5(int n)
{
	for (int i = 1; i <= n; i++)
	{
		result += 1. / pow(i, 5);
	}

	return result;
}

double task6(int n)
{
	for (int i = 1; i <= n; i++)
	{
		result += 1. / pow(2 * i + 1, 2);
	}

	return result;
}

double task7(int n)
{
	for (int i = 1; i <= n; i++)
	{
		result += pow(-1, i) / (2 * i + 1);
	}

	return result;
}

double task8(int n)
{

	for (int i = 1; i <= n; i++)
	{
		int fact = 1.;
		double znam = 0;

		for (int j = 1; j <= i; j++)
		{
			fact *= j;
			znam += 1. / j;
		}

		result += fact / znam;

	}

	return result;
}

double task9(int n)
{
	double last = 0;
	for (int i = 1; i <= n; i++)
	{
		last += 2;

		result = pow(last, 0.5);

		last = result;

	}

	return result;
}

double task10(int n)
{
	double znam = 1;
	for (int i = 1; i <= n; i++)
	{
		znam *= sin(i * pi / 180);

		result += 1 / znam;
	}

	return result;
}

void cases(int task)
{
	int n;
	
	while (true)
	{
		cout << "Enter value of the n : ";
		cin >> n;

		if (n >= 1)
		{
			break;
		}
	}

	switch (task)
	{
	case 1:
		cout << "Result is : " << task1(n) << endl << endl;
		break;
	case 2:
		cout << "Result is : " << task2(n) << endl << endl;
		break;
	case 3:
		cout << "Result is : " << task3(n) << endl << endl;
		break;
	case 4:
		cout << "Result is : " << task4(n) << endl << endl;
		break;
	case 5:
		cout << "Result is : " << task5(n) << endl << endl;
		break;
	case 6:
		cout << "Result is : " << task6(n) << endl << endl;
		break;
	case 7:
		cout << "Result is : " << task7(n) << endl << endl;
		break;
	case 8:
		cout << "Result is : " << task8(n) << endl << endl;
		break;
	case 9:
		cout << "Result is : " << task9(n) << endl << endl;
		break;
	case 10:
		cout << "Result is : " << task10(n) << endl << endl;
		break;
	}
}

int InputTask()
{
	while (true)
	{
		cout << "Enter number of the task:";
		cin >> task;
		if (task <= 10 && task >= 1)
		{
			cases(task);
		}
		else
		{
			cout << "There's no task with this number, try again!" << endl;
		}

		system("pause");
		return 0;
	}

}

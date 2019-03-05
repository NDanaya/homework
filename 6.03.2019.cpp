#include <iostream>

using namespace std;

void inputLength(int&);
double* memoryAllocation(int);
void randomArray(double*, int);
void displayArray(double*, int);
void bubbleSort(double*, int, int);
void newArray(double*, double*, int, int, int);
void swap(double*, double*);
double roundDigits(double, int);

int main()
{
	int n;
	inputLength(n);
	double * c = new double[n];
	randomArray(c, n);
	cout << "Array:   " << endl;
	displayArray(c, n);

	int a;
	cout << "Enter a divisor:  " << endl;
	cin >> a;

	bubbleSort(c, n, a);

	double * d = memoryAllocation(n / 2);

	double k;
	cout << "Enter a digit of rounding:  " << endl;
	cin >> k;

	newArray(c, d, n, k, a);
	displayArray(d, n / 2);

	system("pause");
	return 0;
}

void inputLength(int& n)
{
	cout << "Enter length of array:  " << endl;
	cin >> n;
	if (n < 0)
	{
		cout << "Error" << endl;
		inputLength(n);
	}
}

double* memoryAllocation(int n)
{
	return new double[n];
}

void randomArray(double* array, int n)
{
	for (double* p = array, i = 1; p < array + n; p++, i++)
	{
		*p = rand() % 20 - 9;
	}
}

//void RandomArray(double* array, int n)
//{
//	cout << "Enter array:  ";
//	for (double *p = array; p < array + n; p++)
//	{
//		cin >> *p;
//	}
//}

void displayArray(double* array, int n)
{
	for (double* p = array; p < array + n; p++)
	{
		cout << *p << " ";
	}
	cout << endl;
}


void bubbleSort(double* c, int n, int a)
{
	/*bool swapped = true;

	int i = 1;

	while (swapped)
	{

		swapped = false;

		for (int i = n - 1; i >= 0, i % 2 == 0; i--)
		{
			for (int j = 0; j < i, j % 2 == 0; j++)
			{
				if (int(*(c + j)) % a < int(*(c + j + 1)) % a)
				{
					swap((c + j), (c + j + 1));
					swapped = true;
				}
			}
		}

		i++;
	}*/

	bool swapped = true;

	int i = 1;

	while (swapped)
	{

		swapped = false;

		for (int j = n - 1; j >= i, j % 2 == 0; j--)
		{
			if (int(*(c + j)) % a < int(*(c + j + 1)) % a)
			{
				swap(c[j], c[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

void swap(double* a, double* b)
{
	int z = *a;
	*a = *b;
	*b = z;
}

void newArray(double* c, double* d, int n, int k, int a)
{
	double *p = d;
	double *s = c;
	for (int i = 0, j = 0; j < n; i++, j += 2)
	{
		*(p + i) = roundDigits(*(s + j)/a, k);
	}
}


double roundDigits(double x, int k)
{
	double result = (x * pow(10, k - 1) + 0.5)/ pow(10, k - 1);
	return result;
}
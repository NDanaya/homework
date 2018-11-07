#include <iostream>

using namespace std;



int main()
{
	int first = 1, second = 1;
	int result = 0;

	while (result < 100)
	{
		result = first + second;
		first = second;
		second = result;
	}


	cout << "Minimal three-digit Fibonachi number is : " << result << endl;

	system("pause");
	return 0;
}
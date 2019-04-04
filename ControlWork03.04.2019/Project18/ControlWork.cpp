
#include <iostream>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

const int stringSize = 256;


typedef char*(*encodeRule)(char*);

void stringReplace(char*, char*, char*);
void task(char*, int, encodeRule);
int substringPosition(char*, char*, int);
char* inputString();
int findLength(char*);
char* encode(char*);

int main()
{
	char* string = inputString();
	   
	int n;
	cout << "Length of the word: ";
	cin >> n;

	task(string, n, encode);

	cout << string << endl;

	system("pause");
	return 0;
}


char* inputString()
{
	char* string = new char[stringSize];

	cout << "Enter a string: ";
	cin.getline(string, stringSize);

	return string;
}

int findLength(char* string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		i++;
	}

	return i;
}


char* encode(char* word)
{
	char* encrypted = new char[stringSize];

	const char* capitalLetters = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	const char* lowercaseLetters = "zyxwvutsrqponmlkjihgfedcba";

	int length = 0;

	for (int i = 0; i < findLength(word); i++)
	{

		for (size_t j = 0; j < strlen(capitalLetters); j++)
		{
			if (word[i] == capitalLetters[j] || word[i] == lowercaseLetters[j])
			{

				encrypted[length] = '(';
				length++;

				if (j > 9)
				{
					encrypted[length] = 48 + (j + 1) / 10;
					length++;
				}

				encrypted[length] = 48 + (j + 1) % 10;
				length++;

				encrypted[length] = ')';
				length++;
			}
		}
	}

	encrypted[length] = '\0';

	return encrypted;
}

void task(char* string, int count, encodeRule encodeRule)
{
	char* str = new char[stringSize];
	strcpy(str, string);
	char* newString = strtok(str, " ,.");
	while (newString != NULL)
	{
		if (findLength(newString) == count)
		{
			stringReplace(string, newString, encodeRule(newString));
		}

		newString = strtok(NULL, " ,.-");

	}

	delete[] newString;
	delete[] str;
}


void stringReplace(char* str, char* substing, char* replace)
{
	char* newString = new char[stringSize];

	int newLength = findLength(replace),
		oldLength = findLength(substing),
		sLength = findLength(str),
		start = 0,
		oldStart = 0,
		count = 0,
		difference = newLength - oldLength;

	int index = substringPosition(str, substing, start);

	for (int i = 0; i < index; i++)
	{
		newString[i] = str[i];
	}

	while (index != -1)
	{
		for (int j = index + count * (difference), i = 0; j < index + newLength + count * (difference); j++, i++)
		{
			newString[j] = replace[i];
		}
		start = index + newLength;

		int newIndex = substringPosition(str, substing, start);

		while (newIndex != -1)
		{
			for (int i = index + newLength + count * (difference), j = index + oldLength; j < newIndex; i++, j++)
			{
				newString[i] = str[j];
			}
			break;
		}

		while (newIndex == -1)
		{
			for (int i = index + newLength + count * (difference), j = index + oldLength; j < sLength; i++, j++)
			{
				newString[i] = str[j];
			}
			break;
		}

		index = substringPosition(str, substing, start);
		count++;
	}

	newString[findLength(str) + difference] = '\0';
	strcpy(str, newString);
}

int substringPosition(char* str, char* substring, int start)
{
	int n = findLength(str),
		m = findLength(substring);

	if (m > n)
	{
		return -1;
	}

	int count = 0,
		index = -1;

	for (int i = start; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (substring[j] == str[i + count])
			{
				index = i;
				count++;
				if (j == m - 1)
				{
					return index;
				}
			}
			else
			{
				index = -1;
				count = 0;
				break;
			}
		}
	}
	return index;
}

		
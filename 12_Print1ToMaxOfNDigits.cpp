#include <iostream>
#include <string>
using namespace std;
void Print1ToMaxOfNDigits(int n);
bool Increment(string &number);
void PrintNumber(string number);
void Print1ToMaxOfNDigits1(int n);
void Print1ToMaxOfNDigits1Recursively(string &number, int &count, int index);
void test();
void test1();
int main(void)
{
	test1();
	system("PAUSE");
	return 0;
}
void test()
{
	int n;
	cout << "Input: ";
	while (cin >> n)
	{
		Print1ToMaxOfNDigits(n);
		cout << endl;
		cout << "Input: ";
	}
}
void test1()
{
	int n;
	cout << "Input: ";
	while (cin >> n)
	{
		Print1ToMaxOfNDigits1(n);
		cout << endl;
		cout << "Input: ";
	}
}
void Print1ToMaxOfNDigits(int n)
{
	int count = 0;
	if (n < 0)
		return;
	string number(n, '0');
	while (!Increment(number))
	{
		PrintNumber(number);
		count++;
		if (count == 10)
		{
			cout << endl;
			count = 0;
		}
	}
}
bool Increment(string &number)
{
	bool isOverflow = false;
	int length = number.size();
	int nTakeOver = 0;
	for (int i = length - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == length - 1)
			nSum++;
		if (nSum >= 10)
		{
			if (i == 0)
				isOverflow = true;
			else
			{
				nSum -= 10;
				number[i] = nSum + '0';
				nTakeOver = 1;
			}
		}
		else
		{
			number[i] = nSum + '0';
			break;
		}
	}
	return isOverflow;
}
void PrintNumber(string number)
{
	int i = 0;
	while (number[i] == '0')
		i++;
	cout << number.substr(i) << " ";
}
void Print1ToMaxOfNDigits1(int n)
{
	int count = 0;
	if (n <= 0)
		return;
	string number(n, '0');
	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigits1Recursively(number, count, 0);
	}
}
void Print1ToMaxOfNDigits1Recursively(string &number, int &count, int index)
{
	if (index == number.size() - 1)
	{
		count++;
		PrintNumber(number);
		if (count == 20)
		{
			cout << endl;
			count == 0;
		}
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigits1Recursively(number, count, index + 1);
	}
}
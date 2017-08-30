#include <iostream>
using namespace std;

int NumbersOf1Between1AndN(int n);
int NumbersOf1(const char *strN);
int PowerBase10(unsigned int n);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

int NumbersOf1Between1AndN(int n)
{
	if (n <= 0)
		return 0;
	char strN[50];
	sprintf_s(strN, "%d", n);
	return NumbersOf1(strN);
}

int NumbersOf1(const char *strN)
{
	if (strN == NULL || *strN == '\0')
		return 0;
	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));
	if (length == 1 && first == 0)
		return 0;
	if (length == 1 && first > 0)
		return 1;
	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = PowerBase10(length - 1);
	else if (first == 1)
		numFirstDigit = atoi(strN + 1) + 1;
	int numOtherDigit = first * (length - 1) * PowerBase10(length - 2);
	int numRecursive = NumbersOf1(strN + 1);
	return numFirstDigit + numOtherDigit + numRecursive;
}

int PowerBase10(unsigned int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
		result *= 10;
	return result;
}

void test()
{
	cout << "Test: " << endl;
	int n;
	while (cin >> n)
	{
		int res = NumbersOf1Between1AndN(n);
		cout << res << endl;
	}
}
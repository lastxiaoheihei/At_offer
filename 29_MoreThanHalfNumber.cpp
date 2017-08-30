#include <iostream>
#include <vector>
using namespace std;

int MoreThanHalfNumber(int *num, int length)
{
	if (num == NULL || length <= 0)
		return INT_MAX;
	int result = num[0];
	int times = 1;
	for (int i = 1; i < length; i++)
	{
		if (times == 0)
		{
			result = num[i];
			times = 1;
		}
		else if (num[i] == result)
			times++;
		else
			times--;
	}
	times = 0;
	for (int i = 0; i < length; i++)
	{
		if (num[i] == result)
			times++;
	}
	if (times >= length / 2 + 1)
		return result;
	else
	{
		cout << "No number more than half." << endl;
		return INT_MAX;
	}
}

void test()
{
	cout << "Test: " << endl;
	int num[11] = { 1, 2, 3, 4, 5, 6, 1, 1, 1, 1 };
	int pNum = MoreThanHalfNumber(num, 11);
	cout << pNum << endl;
}

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}
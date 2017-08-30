#include <iostream>

int GetUglyNumber(int index);
int Min(int number1, int number2, int number3);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

int GetUglyNumber(int index)
{
	if (index <= 0)
		return 0;
	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	while (nextUglyIndex < index)
	{
		int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		pUglyNumbers[nextUglyIndex] = min;

		while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
			pMultiply2++;
		while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
			pMultiply3++;
		while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
			pMultiply5++;

		nextUglyIndex++;
	}

	int ugly = pUglyNumbers[index - 1];
	delete[]pUglyNumbers;
	return ugly;
}

int Min(int number1, int number2, int number3)
{
	int min = (number1 < number2) ? number1 : number2;
	min = (number3 < min) ? number3 : min;

	return min;
}

void test()
{
	std::cout << "Test: " << std::endl;
	int index;
	std::cout << "Input: ";
	while (std::cin >> index)
	{
		std::cout << "The " << index << "th ugly number is " \
			<< GetUglyNumber(index) << std::endl;
		std::cout << "Input: ";
	}
}
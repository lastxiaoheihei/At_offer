#include <iostream>
#include <vector>
using namespace std;
int Min(vector<int> numbers);
int MinInOrder(vector<int> numbers, int frontIndex, int rearIndex);
void display(vector<int> numbers);
void test1();
void test2();
int main()
{
	test1();
	test2();
	system("PAUSE");
	return 0;
}
int Min(vector<int> numbers)
{
	int length = numbers.size();
	if (length <= 0)
		return INT_MIN;
	int frontIndex = 0, rearIndex = length - 1;
	int midIndex = frontIndex;
	while (numbers[frontIndex] >= numbers[rearIndex])
	{
		if (rearIndex - frontIndex == 1)
		{
			midIndex = rearIndex;
			break;
		}
		midIndex = (frontIndex + rearIndex) >> 1;
		if (numbers[frontIndex] == numbers[rearIndex] && numbers[midIndex] == numbers[frontIndex])
			return MinInOrder(numbers, frontIndex, rearIndex);
		if (numbers[midIndex] >= numbers[rearIndex])
			frontIndex = midIndex;
		else if (numbers[midIndex] <= numbers[frontIndex])
			rearIndex = midIndex;
	}
	return numbers[midIndex];
}
int MinInOrder(vector<int> numbers, int frontIndex, int rearIndex)
{
	int minNumber = numbers[frontIndex];
	while (++frontIndex <= rearIndex)
	{
		if (numbers[frontIndex] < minNumber)
			minNumber = numbers[frontIndex];
	}
	return minNumber;
}
void display(vector<int> numbers)
{
	for (auto num : numbers)
		cout << num << " ";
	cout << endl;
}
void test1()
{
	cout << "测试用例1: " << endl;
	vector<int> number1 = { 6, 7, 8, 1, 2, 3, 4, 5 };
	display(number1);
	cout << "最小值为: " << Min(number1) << endl;
	vector<int> number2 = { 1, 2, 3, 4, 5, 6, 7 ,8 };
	display(number2);
	cout << "最小值为: " << Min(number2) << endl;
	cout << endl;
}
void test2()
{
	cout << "测试用例2: " << endl;
	vector<int> number1;
	display(number1);
	cout << "最小值为: " << Min(number1) << endl;
	vector<int> number2 = { 1, 0, 1, 1, 1, 1 };
	display(number2);
	cout << "最小值为: " << Min(number2) << endl;
	cout << endl;
}
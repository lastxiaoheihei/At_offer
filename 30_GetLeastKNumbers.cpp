#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int RandomInRange(int start, int end);
void SwapNumbers(int &num1, int &num2);
int Partition(vector<int> &num, int start, int end);
vector<int> GetLeastKNumbers(vector<int> input, int k);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

int RandomInRange(int start, int end)
{
	srand((unsigned int)time(NULL));
	return rand() % (end + 1 - start) + start;
}

void SwapNumbers(int &num1, int &num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int Partition(vector<int> &num, int start, int end)
{
	int reference = RandomInRange(start, end);
	SwapNumbers(num[reference], num[end]);
	int front = start - 1, index = start;
	while (index < end)
	{
		if (num[index] < num[end])
		{
			front++;
			if (front != index)
				SwapNumbers(num[front], num[index]);
		}
		index++;
	}
	front++;
	SwapNumbers(num[front], num[end]);
	return front;
}

vector<int> GetLeastKNumbers(vector<int> num, int k)
{
	int length = num.size();
	vector<int> result;
	if (length <= 0 || k <= 0 || k > length)
		return result;
	int start = 0, end = length - 1;
	int index = Partition(num, 0, length - 1);
	while (index != k - 1)
	{
		if (index > k - 1)
		{
			end = index - 1;
			index = Partition(num, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(num, start, end);
		}
	}
	for (int i = 0; i < k; i++)
		result.push_back(num[i]);
	return result;
}

void test()
{
	cout << "Test: " << endl;
	vector<int> num1 = { 1, 2, 3, 6, 4, 5, 7, 8, 9, 4, 3, 0, 5, 1, 7 };
	vector<int> res1 = GetLeastKNumbers(num1, 100);
	for (auto n : res1)
		cout << n << " ";
	cout << endl;
}


#include <iostream>
#include <vector>
using namespace std;

int GreatestSumOfSubarray(vector<int> num, vector<int> &subarray);
int GreatestSumOfSubarray(vector<int> num);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

int GreatestSumOfSubarray(vector<int> num, vector<int> &subarray)
{
	int length = num.size();
	if (length == 0)
		return 0;
	int start = 0, end = 0;
	int maxSum = INT_MIN, curSum = INT_MIN;
	for (int i = 0; i < length; i++)
	{
		if (num[i] > num[i] + curSum)
		{
			start = i;
			curSum = num[i];
		}
		else
			curSum = num[i] + curSum;
		if (curSum > maxSum)
		{
			end = i;
			maxSum = curSum;
		}
	}
	for (int i = start; i <= end; i++)
		subarray.push_back(num[i]);
	return maxSum;
}

int GreatestSumOfSubarray(vector<int> num)
{
	int length = num.size();
	if (length == 0)
		return 0;
	int *result = new int[length];
	result[0] = num[0];
	for (int i = 1; i < length; i++)
	{
		if (result[i - 1] > 0)
			result[i] = result[i - 1] + num[i];
		else
			result[i] = num[i];
	}
	int maxNum = INT_MIN;
	for (int i = 0; i < length; i++)
		if (result[i] > maxNum)
			maxNum = result[i];
	return maxNum;
	delete[]result;
}

void test()
{
	cout << "Test: " << endl;
	vector<int> num1 = { 3, 1, 9, -5, -7, 8, 13, 10, -5, -17 };
	vector<int> subarray;
	int maxSum = GreatestSumOfSubarray(num1, subarray);
	int maxSum1 = GreatestSumOfSubarray(num1);
	cout << "maxSum = " << maxSum << " " << maxSum1 << endl;
	for (auto n : subarray)
		cout << n << " ";
	cout << endl;
}
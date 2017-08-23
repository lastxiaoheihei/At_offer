#include <iostream>
#include <vector>
using namespace std;
void ReorderArray(vector<int> &pData, bool(*func)(int));
bool isEven(int n);
void test();
void Display(vector<int> pData);
int main(void)
{
	test();
	system("PAUSE");
	return 0;
}
void ReorderArray(vector<int> &pData, bool(*func)(int))
{
	if (pData.size() == 0)
		return;
	int pBegin = 0;
	int pEnd = pData.size() - 1;
	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(pData[pBegin]))
			pBegin++;
		while (pEnd > pBegin && func(pData[pEnd]))
			pEnd--;
		if (pBegin < pEnd)
		{
			int temp = pData[pBegin];
			pData[pBegin] = pData[pEnd];
			pData[pEnd] = temp;
		}
	}

}
bool isEven(int n)
{
	return (n & 0x1) == 0;
}
void Display(vector<int> pData)
{
	for (auto num : pData)
		cout << num << " ";
}
void test()
{
	int number;
	cout << "The test: " << endl;
	vector<int> pData1, pData2 = { 1, 3, 5, 7 }, pData3 = { 1, 2, 4, 6, 7 };
	cout << "Input: " << endl;;
	Display(pData1);
	cout << endl;
	Display(pData2);
	cout << endl;
	Display(pData3);
	cout << endl;
	ReorderArray(pData1, isEven);
	ReorderArray(pData2, isEven);
	ReorderArray(pData3, isEven);
	cout << "Output: ";
	Display(pData1);
	cout << endl;
	Display(pData2);
	cout << endl;
	Display(pData3);
	cout << endl;
}
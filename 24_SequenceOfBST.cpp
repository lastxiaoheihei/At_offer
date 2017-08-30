#include <iostream>
#include <vector>
using namespace std;

bool IsPostOrderOfBST(vector<int> &sequence, int beginIndex, int endIndex);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

bool IsPostOrderOfBST(vector<int> &sequence, int beginIndex, int endIndex)
{
	if (sequence.size() == 0)
		return false;
	int root = sequence[endIndex];
	int i = beginIndex;
	for (; i < endIndex; i++)
	{
		if (sequence[i] > root)
			break;
	}
	int j = i;
	for (; j < endIndex; j++)
	{
		if (sequence[j] < root)
			return false;
	}
	bool left = true;
	if (i > beginIndex)
		left = IsPostOrderOfBST(sequence, beginIndex, i - 1);
	bool right = true;
	if (i < endIndex)
		right = IsPostOrderOfBST(sequence, i, endIndex - 1);
	return (left && right);
}

void test()
{
	cout << "Test:" << endl;
	vector<int> sequence = { 5, 7, 6, 9, 1, 10, 8 };
	cout << IsPostOrderOfBST(sequence, 0, sequence.size() - 1);
	cout << endl;
}
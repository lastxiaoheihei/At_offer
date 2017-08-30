#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool IsPopOrder(vector<int> pPush, vector<int> pPop);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

bool IsPopOrder(vector<int> pPush, vector<int> pPop)
{
	bool result = false;
	int lenPush = pPush.size();
	int lenPop = pPop.size();
	if (lenPush > 0 && lenPop > 0)
	{
		stack<int> pStack;
		int curPush = 0;
		int curPop = 0;
		while (curPop < lenPop)
		{
			if (curPush >= lenPush)
				break;
			while (pPush[curPush] != pPop[curPop])
			{
				pStack.push(pPush[curPush]);
				++curPush;
				if (curPush >= lenPush)
					break;
			}
			curPush++;
			while (curPop < lenPop - 1 && !pStack.empty() && pStack.top() == pPop[++curPop])
				pStack.pop();
		}
		if (pStack.empty() && curPop == lenPop - 1 && curPush == lenPush)
			result = true;
	}
	return result;
}

void test()
{
	cout << "Test: " << endl;
	vector<int> pushNumber1 = { 1, 2, 3, 4, 5 };
	vector<int> popNumber1 = { 1, 3, 2, 5, 4 };
	cout << IsPopOrder(pushNumber1, popNumber1) << endl;
}
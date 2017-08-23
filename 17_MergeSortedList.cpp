#include <iostream>
#include "LinkList.h"
using namespace std;

LinkNode* MergeSortedList(LinkNode *pHead1, LinkNode *pHead2);
void CreateList(LinkNode *&pHead, vector<int> data);
void Display(LinkNode *pHead);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

void test()
{
	cout << "Test1: " << endl;
	vector<int> data1 = { 1, 3, 4, 6, 8, 9 };
	vector<int> data2 = { 3, 5, 6, 7, 8, 9 };
	LinkNode *pHead1 = NULL, *pHead2 = NULL;
	CreateList(pHead1, data1);	CreateList(pHead2, data2);
	cout << "Input: ";
	Display(pHead1);	cout << "and ";	Display(pHead2);
	cout << endl;
	LinkNode *pMergeListHead = MergeSortedList(pHead1, pHead2);
	cout << "Output: ";
	Display(pMergeListHead);
	cout << endl;
}

LinkNode* MergeSortedList(LinkNode *pHead1, LinkNode *pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;
	LinkNode *pMergeHead = NULL;
	if (pHead1->data <= pHead2->data)
	{
		pMergeHead = pHead1;
		pMergeHead->next = MergeSortedList(pHead1->next, pHead2);
	}
	else
	{
		pMergeHead = pHead2;
		pMergeHead->next = MergeSortedList(pHead1, pHead2->next);
	}
	return pMergeHead;
}
#include <iostream>
#include <stack>
using namespace std;
struct LinkNode {
	int m_nKey;
	LinkNode *m_pNext;
};
void PrintListReversing_Recursively(LinkNode *pHead);
void PrintListReversing_Iteratively(LinkNode *pHead);
void test1();
void test2();
void test3();
int main()
{
	test1();
	test2();
	test3();
	system("PAUSE");
	return 0;
}
void PrintListReversing_Recursively(LinkNode *pHead)
{
	if (pHead != NULL)
	{
		PrintListReversing_Recursively(pHead->m_pNext);
		cout << pHead->m_nKey << " ";
	}
}
void PrintListReversing_Iteratively(LinkNode *pHead)
{
	stack<LinkNode *> nodes;
	LinkNode *pCurrentNode = pHead;
	while (pCurrentNode != NULL)
	{
		nodes.push(pCurrentNode);
		pCurrentNode = pCurrentNode->m_pNext;
	}
	while (!nodes.empty())
	{
		pCurrentNode = nodes.top();
		cout << pCurrentNode->m_nKey << " ";
		nodes.pop();
	}
}
void test1()
{
	LinkNode *pNode = NULL;
	LinkNode *pCurrentNode = pNode;
	cout << "测试用例1: " << endl;
	cout << "输入链表: ";
	while (pCurrentNode != NULL)
	{
		cout << pCurrentNode->m_pNext << " ";
		pCurrentNode = pCurrentNode->m_pNext;
	}
	cout << endl;
	cout << "递归方法: ";
	PrintListReversing_Recursively(pNode);
	cout << endl;
	cout << "非递归方法: ";
	PrintListReversing_Iteratively(pNode);
	cout << endl;
	cout << endl;
}
void test2()
{
	LinkNode *pNode = new LinkNode;
	LinkNode *pCurrentNode = pNode;
	pNode->m_nKey = 1;
	pNode->m_pNext = NULL;
	cout << "测试用例2: " << endl;
	cout << "输入链表: ";
	while (pCurrentNode != NULL)
	{
		cout << pCurrentNode->m_nKey << " ";
		pCurrentNode = pCurrentNode->m_pNext;
	}
	cout << endl;
	cout << "递归方法: ";
	PrintListReversing_Recursively(pNode);
	cout << endl;
	cout << "非递归方法: ";
	PrintListReversing_Iteratively(pNode);
	cout << endl;
	cout << endl;
}
void test3()
{
	LinkNode *pNode = new LinkNode;
	LinkNode *pCurrentNode = NULL, *pRearNode = NULL;
	pNode->m_nKey = 0;
	pRearNode = pNode;
	for (int i = 1; i <= 6; i++)
	{
		pCurrentNode = new LinkNode;
		pCurrentNode->m_nKey = i;
		pRearNode->m_pNext = pCurrentNode;
		pRearNode = pCurrentNode;
	}
	pRearNode->m_pNext = NULL;
	cout << "测试用例3: " << endl;
	cout << "输入链表: ";
	pCurrentNode = pNode;
	while (pCurrentNode != NULL)
	{
		cout << pCurrentNode->m_nKey << " ";
		pCurrentNode = pCurrentNode->m_pNext;
	}
	cout << endl;
	cout << "递归方法: ";
	PrintListReversing_Recursively(pNode);
	cout << endl;
	cout << "非递归方法: ";
	PrintListReversing_Iteratively(pNode);
	cout << endl;
	cout << endl;
}
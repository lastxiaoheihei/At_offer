#include <iostream>
#include <vector>
using namespace std;
struct LinkNode {
	int data;
	LinkNode *next;
};
void CreateList(LinkNode *&head, vector<int> data);
LinkNode* KthNodeFromEnd(LinkNode *head, unsigned int k);
void test();
int main(void)
{
	test();
	system("PAUSE");
	return 0;
}
LinkNode* KthNodeFromEnd(LinkNode *head, unsigned int k)
{
	if (head == NULL || k == 0)
		return NULL;
	LinkNode *preNode = head;
	LinkNode *pBehind = head;
	for (unsigned int i = 1; i <= k; i++)
	{
		if (pBehind != NULL)
			pBehind = pBehind->next;
		else
			return NULL;
	}
	while (pBehind != NULL)
	{
		pBehind = pBehind->next;
		preNode = preNode->next;
	}
	return preNode;
}
void CreateList(LinkNode *&head, vector<int> data)
{
	if (data.size() == 0)
		return;
	LinkNode *rear = NULL;
	for (auto num : data)
	{
		LinkNode *newNode = new LinkNode();
		newNode->data = num;
		if (head == NULL)
			rear = head = newNode;
		rear->next = newNode;
		rear = rear->next;
	}
	rear->next = NULL;
}
void test()
{
	LinkNode *head = NULL;
	vector<int> data = { 4, 5, 3, 7, 2, 8, 4 };
	cout << "Test: " << endl;
	CreateList(head, data);
	unsigned int k ;
	while (cin >> k)
	{
		LinkNode *result = KthNodeFromEnd(head, k);
		if (result != NULL)
			cout << "倒数第" << k << "个节点是: " << result->data << endl;
		else
			cout << "倒数第" << k << "个节点不在链表中" << endl;
	}
}
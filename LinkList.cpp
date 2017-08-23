#include "LinkList.h"
void CreateList(LinkNode *&pHead, vector<int> data)
{
	if (data.size() == 0)
		return;
	LinkNode *rear = NULL;
	for (auto num : data)
	{
		LinkNode *newNode = new LinkNode();
		newNode->data = num;
		if (pHead == NULL)
			rear = pHead = newNode;
		rear->next = newNode;
		rear = rear->next;
	}
	rear->next = NULL;
}
void Display(LinkNode *pHead)
{
	LinkNode *curNode = pHead;
	if (pHead == NULL)
		cout << "Á´±íÎª¿Õ: ";
	else
	{
		while (curNode != NULL)
		{
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
	}
}
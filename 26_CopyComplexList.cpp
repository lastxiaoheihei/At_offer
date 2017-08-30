#include <iostream>
#include <vector>
#include <map>
#include "LinkList.h"
using namespace std;

extern void CreateComplexList(ComplexListNode *&pHead, vector<int> data);
extern void DisplayList(ComplexListNode *pHead);

ComplexListNode* Clone(ComplexListNode *pHead);
void CloneNodes(ComplexListNode *pHead);
void connectArbitraryNode(ComplexListNode *pHead);
ComplexListNode* ReconnectNodes(ComplexListNode *pHead);
ComplexListNode* Clone1(ComplexListNode *pHead);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

ComplexListNode* Clone(ComplexListNode *pHead)
{
	if (pHead == NULL)
		return NULL;
	CloneNodes(pHead);
	connectArbitraryNode(pHead);
	return ReconnectNodes(pHead);
}

void CloneNodes(ComplexListNode *pHead)
{
	ComplexListNode *currentNode = pHead;
	while (currentNode != NULL)
	{
		ComplexListNode *newNode = new ComplexListNode();
		newNode->data = currentNode->data;
		newNode->arbitrary = NULL;
		newNode->next = currentNode->next;
		currentNode->next = newNode;
		currentNode = newNode->next;
	}
}

void connectArbitraryNode(ComplexListNode *pHead)
{
	ComplexListNode *currentNode = pHead;
	while (currentNode != NULL)
	{
		ComplexListNode *cloneNode = currentNode->next;
		if (currentNode->arbitrary != NULL)
			cloneNode->arbitrary = currentNode->arbitrary->next;
		currentNode = cloneNode->next;
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode *pHead)
{
	ComplexListNode *currentNode = pHead, *cloneHead = NULL, *cloneNode = NULL;
	if (currentNode != NULL)
	{
		cloneHead = cloneNode = currentNode->next;
		currentNode->next = cloneNode->next;
		currentNode = currentNode->next;
	}
	while (currentNode != NULL)
	{
		cloneNode->next = currentNode->next;
		cloneNode = cloneNode->next;
		currentNode->next = cloneNode->next;
		currentNode = currentNode->next;
	}
	return cloneHead;
}

ComplexListNode* Clone1(ComplexListNode *pHead)
{
	ComplexListNode *currentNode = pHead, *newHead = NULL, *rearNode = NULL;
	map<ComplexListNode *, ComplexListNode *> indexNodes;
	while (currentNode != NULL)
	{
		ComplexListNode *newNode = new ComplexListNode();
		newNode->data = currentNode->data;
		newNode->arbitrary = NULL;
		if (newHead == NULL)
		{
			rearNode = newHead = newNode;
			indexNodes.insert(make_pair(currentNode, rearNode));
		}
		else
		{
			rearNode->next = newNode;
			rearNode = rearNode->next;
			indexNodes.insert(make_pair(currentNode, rearNode));
		}
		currentNode = currentNode->next;
	}
	rearNode->next = NULL;
	currentNode = pHead;
	while (currentNode != NULL)
	{
		if (currentNode->arbitrary != NULL)
			indexNodes[currentNode]->arbitrary = indexNodes[currentNode->arbitrary];
		currentNode = currentNode->next;
	}
	return newHead;
}

void test()
{
	cout << "Test: " << endl;
	vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8 };
	ComplexListNode *pHead = NULL;
	CreateComplexList(pHead, data);
	DisplayList(pHead);
	cout << endl;
	ComplexListNode *newHead = NULL;
	newHead = Clone1(pHead);
	DisplayList(newHead);
	cout << endl;
}
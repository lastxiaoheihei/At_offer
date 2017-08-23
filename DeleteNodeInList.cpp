#include <iostream>
using namespace std;
struct ListNode
{
	int data;
	ListNode *next;
};
void DeleteNodeInList(ListNode *&head, ListNode *pToDeleted);
void Display(ListNode *head);
void test1();
void test2();
//void test3();
int main(void)
{
	test1();
	test2();
	//test3();
	system("PAUSE");
	return 0;
}
void DeleteNodeInList(ListNode *&head, ListNode *pToDeleted)
{
	if (head == NULL || pToDeleted == NULL)
		return;
	if (pToDeleted->next != NULL)
	{
		ListNode *pNext = pToDeleted->next;
		pToDeleted->data = pNext->data;
		pToDeleted->next = pNext->next;
		delete pNext;
		pNext = NULL;
	}
	else if (pToDeleted == head)
	{
		delete pToDeleted;
		pToDeleted = NULL;
		head = NULL;
	}
	else
	{
		ListNode *pNode = head;
		while (pNode->next != pToDeleted)
			pNode = pNode->next;
		pNode->next = NULL;
		delete pToDeleted;
		pToDeleted = NULL;
	}
}
void test1()
{
	ListNode *head = NULL, *pToDeleted = NULL;
	cout << "Test 1: " << endl;
	cout << "The Input: ";
	Display(head);
	cout << endl;
	DeleteNodeInList(head, pToDeleted);
	cout << "Output: ";
	Display(head);
	cout << endl;
	cout << endl;
}
void test2()
{
	ListNode *head = NULL, *pToDeleted = NULL, *rear = NULL;
	for (int i = 0; i <= 10; i++)
	{
		ListNode *newNode = new ListNode();
		newNode->data = i;
		if (head == NULL)
		{
			head = newNode;
			rear = head;
		}
		rear->next = newNode;
		rear = rear->next;
	}
	rear->next = NULL;
	pToDeleted = head;
	cout << "Test 2: " << endl;
	cout << "The input: ";
	Display(head);
	cout << endl;
	DeleteNodeInList(head, pToDeleted);
	cout << "Output: ";
	Display(head);
	cout << endl;
	cout << endl;
}
void Display(ListNode *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}
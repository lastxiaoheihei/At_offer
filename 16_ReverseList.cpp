#include <iostream>
#include <vector>
using namespace std;
struct LinkNode
{
	int data;
	LinkNode *next;
};
void ReverseList(LinkNode *&head);
void test();
void CreateList(LinkNode *&head, vector<int> data);
void Display(LinkNode *head);
int main(void)
{
	test();
	system("PASUE");
	return 0;
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
void ReverseList(LinkNode *&head)
{
	if (head == NULL || head->next == NULL)
		return;
	LinkNode *preNode = NULL, *curNode = head, *nxtNode = curNode->next;
	while (curNode != NULL)
	{
		curNode->next = preNode;
		preNode = curNode;
		curNode = nxtNode;
		if (curNode == NULL)
		{
			head = preNode;
			return;
		}
		nxtNode = nxtNode->next;
	}
}
void Display(LinkNode *head)
{
	LinkNode *curNode = head;
	cout << "Output: ";
	while (curNode != NULL)
	{
		cout << curNode->data << " ";
		curNode = curNode->next;
	}
}
void test()
{
	LinkNode *head = NULL;
	cout << "Test: " << endl;
	vector<int> data = { 1, 2, 3, 4, 5, 6 };
	CreateList(head, data);
	Display(head);
	cout << endl;
	ReverseList(head);
	Display(head);
	cout << endl;
}
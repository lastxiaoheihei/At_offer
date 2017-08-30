#include "BinaryTree.h"
#include <stack>

BinaryTreeNode* CreateBinaryTree(string s)
{
	if (s.size() == 0)
		return NULL;
	BinaryTreeNode *head = NULL, *newNode = NULL;
	stack<BinaryTreeNode *> pStack;
	int k;
	for (auto ch : s)
	{
		switch (ch)
		{
		case '(': pStack.push(newNode); k = 1; break;
		case ')': pStack.pop(); break;
		case ',': k = 2; break;
		default: 
			newNode = new BinaryTreeNode();
			newNode->data = ch - '0';
			newNode->left = newNode->right = NULL;
			if (head == NULL)
				head = newNode;
			else
			{
				switch (k)
				{
				case 1: pStack.top()->left = newNode; break;
				case 2: pStack.top()->right = newNode; break;
				}
			}
		}
	}
	return head;
}

void DisplayBinaryTree(BinaryTreeNode *head)
{
	if (head != NULL)
	{
		cout << head->data;
		if (head->left != NULL || head->right != NULL)
		{
			cout << "(";
			DisplayBinaryTree(head->left);
			if (head->right != NULL)
				cout << ",";
			DisplayBinaryTree(head->right);
			cout << ")";
		}
	}
}

BinaryTreeNode* CreateBST(vector<int> nodesValue)
{
	int length = nodesValue.size();
	BinaryTreeNode *bst = NULL;
	for (int i = 0; i < length; i++)
		InsertBST(bst, nodesValue[i]);
	return bst;
}

void InsertBST(BinaryTreeNode *&bst, int value)
{
	if (bst == NULL)
	{
		bst = new BinaryTreeNode();
		bst->data = value;
		bst->left = bst->right = NULL;
	}
	else if (value == bst->data)
		return;
	else if (value < bst->data)
		InsertBST(bst->left, value);
	else
		InsertBST(bst->right, value);
}
#include "..\..\18_SubStructureInTree\18_SubStructureInTree\BinaryTree.h"
#include <iostream>
#include <string>
#include <deque>
using namespace std;

void PrintTreeFromTopToBottom(BinaryTreeNode *pRoot);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

void PrintTreeFromTopToBottom(BinaryTreeNode *pRoot)
{
	if (pRoot == NULL)
	{
		cout << "Tree is empty." << endl;
		return;
	}
	deque<BinaryTreeNode *> dequeTreeNode;
	dequeTreeNode.push_back(pRoot);
	while (dequeTreeNode.size() > 0)
	{
		BinaryTreeNode *pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		cout << pNode->data << " ";
		if (pNode->left != NULL)
			dequeTreeNode.push_back(pNode->left);
		if (pNode->right != NULL)
			dequeTreeNode.push_back(pNode->right);
	}
}

void test()
{
	cout << "Test: " << endl;
	string s1;
	string s2 = "1(2(3,4(,5)),6(7,8))";
	BinaryTreeNode *pRoot = NULL;
	pRoot = CreateBinaryTree(s1);
	cout << "Input tree: ";
	DisplayBinaryTree(pRoot);
	cout << endl;
	cout << "Output tree: ";
	PrintTreeFromTopToBottom(pRoot);
	cout << endl;
}
#include "..\..\18_SubStructureInTree\18_SubStructureInTree\BinaryTree.h"

extern BinaryTreeNode* CreateBST(vector<int> nodesValue);
extern void InsertBST(BinaryTreeNode *&bst, int value);

BinaryTreeNode* Convert(BinaryTreeNode *pRoot);
BinaryTreeNode* ConvertNode(BinaryTreeNode *pRoot);
void ConvertNode1(BinaryTreeNode *pHead, BinaryTreeNode *&pLastNodeInList);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

BinaryTreeNode* Convert(BinaryTreeNode *pRoot)
{
	BinaryTreeNode *pHeadOfList = ConvertNode(pRoot);
	while (pHeadOfList != NULL && pHeadOfList->left != NULL)
		pHeadOfList = pHeadOfList->left;

	return pHeadOfList;
}

BinaryTreeNode* ConvertNode(BinaryTreeNode *pRoot)
{
	if (pRoot == NULL || pRoot->left == NULL && pRoot->right == NULL)
		return pRoot;
	if (pRoot->left != NULL)
	{
		BinaryTreeNode *leftBehind = ConvertNode(pRoot->left);
		leftBehind->right = pRoot;
		pRoot->left = leftBehind;
	}
	if (pRoot->right != NULL)
	{
		BinaryTreeNode *rightBehind = ConvertNode(pRoot->right);
		while (rightBehind->left != NULL)
			rightBehind = rightBehind->left;
		pRoot->right = rightBehind;
		rightBehind->left = pRoot;
	}
	while (pRoot->right != NULL)
		pRoot = pRoot->right;
	return pRoot;
}

void ConvertNode1(BinaryTreeNode *pHead, BinaryTreeNode *&pLastNodeInList)
{
	if (pHead == NULL)
		return;
	if (pHead->left != NULL)
		ConvertNode1(pHead->left, pLastNodeInList);
	pHead->left = pLastNodeInList;
	if (pLastNodeInList != NULL)
		pLastNodeInList->right = pHead;
	pLastNodeInList = pHead;
	if (pHead->right != NULL)
		ConvertNode1(pHead->right, pLastNodeInList);
}

void test()
{
	cout << "Test:" << endl;
	vector<int> nodesValue = { 10, 6, 14, 4, 8, 12, 16, 3, 5, 7, 9 };
	BinaryTreeNode *pRoot = NULL;
	pRoot = CreateBST(nodesValue);
	DisplayBinaryTree(pRoot);
	cout << endl;
	pRoot = Convert(pRoot);
	BinaryTreeNode *currentNode = pRoot;
	while (currentNode != NULL)
	{
		cout << currentNode->data << " ";
		currentNode = currentNode->right;
	}
	cout << endl;
}
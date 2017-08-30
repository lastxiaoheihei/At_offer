#include <iostream>
#include "..\..\18_SubStructureInTree\18_SubStructureInTree\BinaryTree.h"
using namespace std;
void MirrorOfBinaryTree(BinaryTreeNode *pRoot);
void test();
int main(void)
{
	test();
	system("PAUSE");
	return 0;
}
void MirrorOfBinaryTree(BinaryTreeNode *pRoot)
{
	if (pRoot == NULL || (pRoot->left == NULL && pRoot->right == NULL))
		return;
	if (pRoot->left != NULL)
		MirrorOfBinaryTree(pRoot->left);
	if (pRoot->right != NULL)
		MirrorOfBinaryTree(pRoot->right);
	BinaryTreeNode *temp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = temp;
}
void test()
{
	string s2 = "1(3(7,8(3,9)),5(6,4))";
	string s1;
	BinaryTreeNode *pRoot = NULL;
	pRoot = CreateBinaryTree(s1);
	cout << "Test: ";
	cout << "The binary tree input is: ";
	DisplayBinaryTree(pRoot);
	cout << endl;
	MirrorOfBinaryTree(pRoot);
	cout << "The mirror tree is: ";
	DisplayBinaryTree(pRoot);
	cout << endl;
}
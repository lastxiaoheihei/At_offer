#include "BinaryTree.h"

extern BinaryTreeNode* CreateBinaryTree(string s);
extern void DisplayBinaryTree(BinaryTreeNode *head);
bool HasSubtree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2);
bool DosTree1HaveTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

bool HasSubtree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
	if (pRoot2 == NULL)	return true;
	bool result = false;
	if (pRoot1 != NULL)
	{
		if (pRoot1->data == pRoot2->data)
			result = DosTree1HaveTree2(pRoot1, pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->left, pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->right, pRoot2);
	}
	return result;
}

bool DosTree1HaveTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;
	if (pRoot1->data != pRoot2->data)
		return false;
	return DosTree1HaveTree2(pRoot1->left, pRoot2->left) && \
		DosTree1HaveTree2(pRoot1->right, pRoot2->right);
}
void test()
{
	cout << "Test: " << endl;
	string s1 = "1(2(4,5(6(8,9(,10)),7)),3)";
	string s2 = "2(4,6)";
	BinaryTreeNode *pRoot1 = CreateBinaryTree(s1);
	BinaryTreeNode *pRoot2 = CreateBinaryTree(s2);
	cout << "树1: ";	DisplayBinaryTree(pRoot1);	cout << endl;
	cout << "树2: ";	DisplayBinaryTree(pRoot2);	cout << endl;
	cout << "树2是树1的子结构: " << HasSubtree(pRoot1, pRoot2);
	cout << endl;
}
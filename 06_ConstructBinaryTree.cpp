#include <iostream>
#include <vector>
using namespace std;
struct BinaryTreeNode {
	int key;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};
BinaryTreeNode* Construct(vector<int> inorder, vector<int> preorder);
BinaryTreeNode* ConstructBinaryTree
(
	vector<int> &inorder, int strartInorder, int endInorder,
	vector<int> &preorder, int startPreorder, int endPreorder
);
void DisplayBinaryTree(BinaryTreeNode *root);
void test1();
void test2();
int main()
{
	//test1();
	test2();
	system("PAUSE");
	return 0;
}
BinaryTreeNode* Construct(vector<int> inorder, vector<int> preorder)
{
	if (inorder.empty() || preorder.empty())
		return NULL;
	return ConstructBinaryTree(inorder, 0, inorder.size() - 1,\
		preorder, 0, preorder.size() - 1);
}
BinaryTreeNode* ConstructBinaryTree
(
	vector<int> &inorder, int startInorder, int endInorder,
	vector<int> &preorder, int startPreorder, int endPreorder
)
{
	int rootValue = preorder[startPreorder];
	BinaryTreeNode *root = new BinaryTreeNode();
	root->key = rootValue;
	root->left = NULL;	root->right = NULL;
	if (startInorder == endInorder)
	{
		if (startPreorder == endPreorder && inorder[startInorder] == preorder[startPreorder])
			return root;
		else
			throw exception("Invalid input!");
	}
	int position = 0;
	vector<int>::iterator iter = inorder.begin() + startInorder;
	while (iter != inorder.begin() + endInorder)
	{
		if (rootValue != *iter)
		{
			position++;
			iter++;
		}
		else
			break;
	}
	if (position >= endInorder - startInorder + 1)
		throw exception("Invalid input!");
	if (position - 1 >= 0)
		root->left = ConstructBinaryTree(inorder, startInorder, position - 1 + startInorder, \
			preorder, startPreorder + 1, position + startPreorder);
	if (endInorder >= position + 1 + startInorder)
		root->right = ConstructBinaryTree(inorder, position + 1 + startInorder, \
			endInorder, preorder, position + 1 + startPreorder, endPreorder);
	return root;

}
void DisplayBinaryTree(BinaryTreeNode *root)
{
	if (root != NULL)
	{
		cout << root->key;
		if (root->left != NULL || root->right != NULL)
		{
			cout << '(';
			DisplayBinaryTree(root->left);
			if (root->right!=NULL)
				cout << ',';
			DisplayBinaryTree(root->right);
			cout << ')';
		}
	}
}
void test1()
{
	vector<int> inorder = { 2, 4, 6, 1, 7, 5, 3, 8 };
	vector<int> preorder = { 5, 4, 2, 1, 6, 7, 3, 8 };
	BinaryTreeNode *root = NULL;
	root = Construct(inorder, preorder);
	DisplayBinaryTree(root);
}
void test2()
{
	vector<int> inorder = { 5, 3, 8 };
	vector<int> preorder = { 5, 3, 9 };
	BinaryTreeNode *root = NULL;
	root = Construct(inorder, preorder);
	DisplayBinaryTree(root);
}
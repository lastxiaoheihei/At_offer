#include <iostream>
#include "..\..\18_SubStructureInTree\18_SubStructureInTree\BinaryTree.h"
#include <vector>
#include <string>
using namespace std;

void FindPath(BinaryTreeNode *pRoot, int expectedSum);
void FindPath(BinaryTreeNode *pRoot, int expectedSum, vector<int> &path, int currentSum);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

void FindPath(BinaryTreeNode *pRoot, int expectedSum)
{
	if (pRoot == NULL)
	{
		cout << "The tree is empty." << endl;
		return;
	}
	vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, expectedSum, path, currentSum);
}

void FindPath
(
	BinaryTreeNode *pRoot,
	int expectedSum,
	vector<int> &path,
	int currentSum
)
{
	path.push_back(pRoot->data);
	currentSum += pRoot->data;
	if (pRoot->left == NULL && pRoot->right == NULL && currentSum == expectedSum)
	{
			for (auto num : path)
				cout << num << " ";
			cout << endl;
	}
	if (pRoot->left != NULL)
		FindPath(pRoot->left, expectedSum, path, currentSum);
	if (pRoot->right != NULL)
		FindPath(pRoot->right, expectedSum, path, currentSum);
	path.pop_back();
	currentSum -= pRoot->data;
}

void test()
{
	cout << "Test: " << endl;
	string s1;
	string s2 = "1(2(5(7,6),4(6,7)),3(9(1),2(8,)))";
	BinaryTreeNode *pRoot = NULL;
	pRoot = CreateBinaryTree(s1);
	DisplayBinaryTree(pRoot);
	cout << endl;
	FindPath(pRoot, 14);
}
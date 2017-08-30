#include <iostream>
#include <vector>
using namespace std;

void PrintMatrix(vector<vector<int>>);
void PrintMatrixClockwisely(vector<vector<int>> matrix);
void PrintMatrixInCircle(vector<vector<int>> matrix, int start);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

void PrintMatrix(vector<vector<int>> matrix)
{
	if (matrix.size() == 0)
		cout << "matrix is empty!" << endl;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void PrintMatrixClockwisely(vector<vector<int>> matrix)
{
	if (matrix.size() == 0)
	{
		cout << "matrix is empty!" << endl;
		return;
	}
	int start = 0;
	while (start * 2 < matrix.size() && start * 2 < matrix[0].size())
	{
		PrintMatrixInCircle(matrix, start);
		++start;
	}

}

void PrintMatrixInCircle(vector<vector<int>> matrix, int start)
{
	int endX = matrix[0].size() - start - 1;
	int endY = matrix.size() - start - 1;
	for (int i = start; i <= endX; ++i)
		cout << matrix[start][i] << " ";
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
			cout << matrix[i][endX] << " ";
	}
	if (start < endX && start < endY)	
	{
		for (int i = endX - 1; i >= start; --i)
			cout << matrix[endY][i] << " ";
	}
	if (start < endX && start < endY - 1)
	{
		for (int i = endY - 1; i > start; --i)
			cout << matrix[i][start] << " ";
	}
}

void test()
{
	cout << "Test: ";
	vector<vector<int>> matrix = { {1, 2, 3, 4, 5, 6},
								   {2, 4, 6, 8, 0, 2},
								   {1, 3, 5, 7, 9, 1} };
	cout << "Input matrix is:" << endl;
	PrintMatrix(matrix);
	cout << "Print matrix clockwisely: " << endl;
	PrintMatrixClockwisely(matrix);
}
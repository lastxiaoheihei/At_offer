#include <iostream>
using namespace std;
bool Find(int *matrix, int rows, int colums, int number);
int main(void)
{
	int matrix1[][4] = { 1, 2, 3, 4,
						5, 6, 7, 8,
						9, 10, 11, 12,
						13, 14, 15, 16 };
	bool flag = Find((int *)matrix1, 4, 4, 1);
	cout << "查找最小值得结果: " << flag << endl;
	flag = Find((int *)matrix1, 4, 4, 16);
	cout << "查找最大值的结果: " << flag << endl;
	flag = Find((int *)matrix1, 4, 4, 10);
	cout << "查找中间值的结果: " << flag << endl;
	flag = Find((int *)matrix1, 4, 4, 20);
	cout << "查找不存在值的结果: " << flag << endl;
	flag = Find(NULL, 0, 0, 15);
	cout << "查找NULL特殊值的结果: " << flag << endl;
}

bool Find(int *matrix, int rows, int colums, int number)
{
	bool found = false;
	if (NULL != matrix && rows > 0 && colums > 0)
	{
		int row = 0, colum = colums - 1;
		while (row < rows && colum >= 0)
		{
			if (matrix[row * colums + colum] == number)
			{
				cout << "row: " << row << "colum: " << colum << endl;
				found = true;
				break;
			}
			else if (matrix[row * colums + colum] < number)
				row++;
			else
				colum--;
		}
	}
	return found;
}
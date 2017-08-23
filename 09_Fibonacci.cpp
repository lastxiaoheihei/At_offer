#include <iostream>
using namespace std;
long long Fibonacci(unsigned int n);
void test();
int main(void)
{
	test();
	system("PAUSE");
	return 0;
}
long long Fibonacci(unsigned int n)
{
	if (n == 0)	return 0;
	if (n == 1)	return 1;
	int FibN;
	int FibNOne = 0;
	int FibNTwo = 1;
	for (int i = 2; i <= n; i++)
	{
		FibN = FibNOne + FibNTwo;
		FibNOne = FibNTwo;
		FibNTwo = FibN;
	}
	return FibN;
}
void test()
{
	unsigned int n;
	cout << "测试用例: " << endl;
	cout << "输入: ";
	while (cin >> n)
	{
		cout << "输出: " << Fibonacci(n) << endl;
		cout << "输入: ";
	}
}
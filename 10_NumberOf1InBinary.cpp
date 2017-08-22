#include <iostream>
using namespace std;
int NumberOf1InBinary1(int n);
int NumberOf1InBinary2(int n);
void test();
int main()
{
	test();
	system("PAUSE");
	return 0;
}
int NumberOf1InBinary1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (flag & n)
			count++;
		flag = flag << 1;
	}
	return count;
}
int NumberOf1InBinary2(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = (n - 1) & n;
	}
	return count;
}
void test()
{
	int n;
	cout << "²âÊÔÓÃÀý: " << endl;
	while (cin >> n)
	{
		cout << "Êä³ö: " << NumberOf1InBinary1(n);
		cout << "Êä³ö: " << NumberOf1InBinary2(n);
		cout << endl;
	}
}
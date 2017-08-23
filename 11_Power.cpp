#include <iostream>                                                                     
using namespace std;
bool g_InvalidInput = false;
double Power(double base, int exponent);
double PowerWithUnsignedExponent(double base, unsigned int exponent);
bool equal(double number1, double number2);
void test();
int main()
{
	test();
	system("PAUSE");
	return 0;
}
double Power(double base, int exponent)
{
	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		cout << "Invalid Input! ";
		return 0.0;
	}
	unsigned int unsignedExponent = (exponent >= 0) ? exponent : -exponent;
	double result = PowerWithUnsignedExponent(base, unsignedExponent);
	if (exponent < 0)
		result = 1.0 / result;
	return result;
}
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)	return 1;
	if (exponent == 1)	return base;
	double result = PowerWithUnsignedExponent(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1)
		result *= base;
	return result;
}
bool equal(double number1, double number2)
{
	if (number1 - number2 < 0.0000001 && number1 - number2 > -0.0000001)
		return true;
	else
		return false;
}
void test()
{
	cout << "测试用例:" << endl;
	double base;
	int exponent;
	cout << "输入: ";
	while (cin >> base && cin >> exponent)
	{
		cout << "输出: " << Power(base, exponent) << endl;
		cout << "输入: ";
	}
}
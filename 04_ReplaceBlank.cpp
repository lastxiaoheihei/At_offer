#include <iostream>
#include <string>
using namespace std;
const unsigned int capability = 50;
void ReplaceBlank(char str[], int lenght);
void test1();
void test2();
void test3();
int main(void)
{
	test1();
	test2();
	test3();
	system("PAUSE");
	return 0;
}
void ReplaceBlank(char str[], int length)
{
	if (str == NULL || length <= 0)
		return;
	int originLength = 0;
	int numberOfBlank = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			numberOfBlank++;
		originLength++;
	}
	int newLength = originLength + 2 * numberOfBlank;
	if (newLength > capability)
		return;
	str[originLength] = '\0';
	int indexOfOrigin = originLength - 1;
	int indexOfNew = newLength - 1;
	while (indexOfOrigin >= 0 && indexOfNew > indexOfOrigin)
	{
		if (str[indexOfOrigin] == ' ')
		{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else
			str[indexOfNew--] = str[indexOfOrigin];
		indexOfOrigin--;
	}
}
void test1()
{
	char str1[capability] = { '\0' };
	ReplaceBlank(str1, capability);
	cout << "²âÊÔÓÃÀý1: " << endl;
	cout << "Êä³öÓÃÀý1: " << str1 << endl;
}
void test2()
{
	char str2[capability] = "jef            jeige          gneigei";
	ReplaceBlank(str2, capability);
	cout << "²âÊÔÓÃÀý2: " << str2 << endl;
	cout << "Êä³öÓÃÀý2: " << str2 << endl;
}
void test3()
{
	char str3[capability] = "fahif fjedf an fdif fejf a j";
	cout << "²âÊÔÓÃÀý3: " << str3 << endl;
	ReplaceBlank(str3, capability);
	cout << "Êä³öÓÃÀý3: " << str3 << endl;
}
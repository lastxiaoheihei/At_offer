#include <iostream>
#include <string>
using namespace std;

char FindFirstNotRepeatingChar(string pString);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

char FindFirstNotRepeatingChar(string pString)
{
	int length = pString.size();
	if (length == 0)
		return '\0';
	unsigned int hashTable[256];
	for (int i = 0; i < 256; i++)
		hashTable[i] = 0;
	for (auto ch : pString)
		hashTable[ch]++;
	for (auto ch : pString)
		if (hashTable[ch] == 1)
			return ch;
	return '\0';
}

void test()
{
	cout << "Test: " << endl;
	string str1;
	cout << "Input: ";
	while (cin >> str1)
	{
		cout << FindFirstNotRepeatingChar(str1) << endl;
		cout << "Input: ";
	}
}
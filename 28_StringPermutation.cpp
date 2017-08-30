#include <stdio.h>
#include <stdlib.h> 

void Permutation(char *pStr);
void Permutation(char *pStr, char *pBegin);
void test();

int main(void)
{
	test();
	system("PAUSE");
	return 0;
}

void Permutation(char *pStr)
{
	if (pStr == NULL)
	{
		return;
	}
	Permutation(pStr, pStr);
}

void Permutation(char *pStr, char *pBegin)
{
	if (pBegin = '\0')
		printf("%s\n", pStr);
	else
	{
		for (char *pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
			Permutation(pStr, pBegin + 1);
			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}

void test()
{
	char pStr[5] = "abcd";
	Permutation(pStr);
}

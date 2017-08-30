#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

bool mincut1(const string& str, const set<string>& dict, vector<string>& temp)
{
	int n = str.length();
	if (n <= 0)	return true;
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		if (find(dict.begin(), dict.end(), str.substr(0, i)) != dict.end())
		{
			flag = true;
			temp.push_back(str.substr(0, i));
			if (i == n)	return true;
			if (mincut1(str.substr(i), dict, temp))
				return true;
			else
				return false;
		}
	}
	if (flag)
		return true;
	else
		return false;
}

void mincut(const string& str, const set<string>& dict)
{
	int n = str.length();
	vector<vector<string>> OutputText;	//保存所有可能的输出情况
	for (int i = 1; i <= n; i++)//找出所有开头子字符串满足的情况，然后分别递归
	{
		if (find(dict.begin(), dict.end(), str.substr(0, i)) != dict.end())
		{
			vector<string> temp;//保存每个递归下符合情况的输出
			temp.push_back(str.substr(0, i));
			if (mincut1(str.substr(i), dict, temp))
				OutputText.push_back(temp);
		}

	}
	if (OutputText.size() == 0)
		cout << "n/a";
	else
	{
		int minLength = 0;
		for (int i = 1; i < OutputText.size() - 1; i++)
			if (OutputText[i].size() < OutputText[minLength].size())
				minLength = i;
		for (auto str : OutputText[minLength])
			cout << str << " ";
	}
}

int main(int argc, const char * argv[])
{
	string strS;
	string dictStr;
	int nDict;
	set<string> dict;

	cin >> strS;
	cin >> nDict;
	for (int i = 0; i < nDict; i++)
	{
		cin >> dictStr;
		dict.insert(dictStr);
	}
	mincut(strS, dict);

	return 0;
}
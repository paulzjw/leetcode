//https://leetcode-cn.com/problems/longest-common-prefix/description/
#include <stdio.h>
#include <vector>

using namespace std;


void printVecotr(const vector<int> &v)
{
	printf("vector is : ");
	for (auto &i : v)
	{
		printf("%d ", i);
	}
	printf("\n");
}

string longestCommonPrefix1(vector<string>& strs) {
	string prefix;
	if (strs.empty())
		return prefix;

	size_t min_len = strs[0].length();
	int	min_index = 0;
	for (size_t i = 0; i < strs.size(); ++i)
	{
		if (strs[i].empty())
			return prefix;
		if (min_len > strs[i].length())
		{
			min_len = strs[i].length();
			min_index = i;
		}
	}

	for (size_t i = 0; i < min_len; ++i)
	{
		bool isAddPrefix = true;
		for (size_t j = 0; j < strs.size() - 1; ++j)
		{
			if (strs[j][i] != strs[j + 1][i])
			{
				isAddPrefix = false;
				break;
			}
		}
		if (isAddPrefix)
			prefix += strs[min_index][i];
		else
			break;
	}
	return prefix;
}

//fastest
string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0) return "";
	if (strs.size() == 1) return strs[0];
	bool con = true;
	int resNum = 0;
	while (con) {
		for (int i = 1; i<strs.size(); i++) {
			if (strs[i][resNum] != strs[0][resNum] || strs[i][resNum] == '\0') {
				con = false;
				break;
			}
		}
		++resNum;
	}
	if (resNum == 1) return "";
	return strs[0].substr(0, resNum - 1);
}

int main()
{
	//int a[] = { 'a', '1', '0' };
	//auto v2 = strStr("101100111", "11");

	vector<string> v = { "123","123","123" };
	string prefix = longestCommonPrefix(v);
	printf("longestCommonPrefix is %s \n", prefix.c_str());
	system("pause");
}
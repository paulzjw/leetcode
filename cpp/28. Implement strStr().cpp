//https://leetcode-cn.com/problems/implement-strstr/description/
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


int strStr(string haystack, string needle) {
	
	if (needle.length() == 0)
		return 0;
	if (haystack.length() < needle.length())
		return -1;
	int hLen = haystack.length();
	int nLen = needle.length();
	for (int i = 0; i < hLen; ++i)
	{
		if (haystack[i] == needle[0])
		{
			if (i + nLen > hLen)
				continue;
			bool isContain = true;
			for (int j = 1; j < nLen; ++j)
			{
				if (haystack[j + i] != needle[j])
				{
					isContain = false;
					break;
				}
			}
			if (isContain)
				return i;
			else
				continue;
		}
	}
	return -1;
}

int main()
{
	int a[] = { 'a', '1', '0' };
	auto v2 = strStr("101100111", "11");
	printf("ret is %d \n",v2);
	system("pause");
}
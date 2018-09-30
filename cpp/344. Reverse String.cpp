//https://leetcode-cn.com/problems/reverse-string/description/
#include <stdio.h>
#include <vector>

using namespace std;




string reverseString(string s) {
	if (s.empty() || s.length() == 1)
		return s;
	size_t start = 0;
	size_t end = s.length() - 1;
	while (start < end)
	{
		swap(s[start], s[end]);
		++start;
		--end;
	}
	return s;
}

int main()
{
	//int a[] = { 'a', '1', '0' };
	//auto v2 = strStr("101100111", "11");

	string prefix = reverseString("hello");
	printf("reverse is %d \n", prefix == "olleh");
	system("pause");
}


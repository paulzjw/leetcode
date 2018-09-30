//https://leetcode-cn.com/problems/plus-one/description/

#include <stdio.h>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	std::vector<int> v;
	bool next_flag = 1;
	for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter)
	{
		int &cur = *iter;
		if (next_flag)
			++cur;
		if (cur == 10)
		{
			cur = 0;
			next_flag = true;
		}
		else
			next_flag = false;
	}
	if (next_flag)
	{
		v.resize(digits.size() + 1);
		copy(digits.begin(), digits.end(), v.begin() + 1);
		v[0] = 1;
	}
	else
	{
		v.assign(digits.begin(), digits.end());
	}

	return v;
}

void printVecotr(const vector<int> &v)
{
	printf("vector is : ");
	for (int i = 0; i < v.size(); ++i)
	{
		printf("%d", v[i]);
	}
	printf("\n");
}

int main()
{
	std::vector<int> v{ 1, 2, 3, 9 };
	auto v2 = plusOne(v);
	printVecotr(v2);
	system("pause");
}
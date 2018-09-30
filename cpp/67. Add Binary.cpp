// https://leetcode-cn.com/problems/add-binary/description/
#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	int size = nums.size();
	unordered_map<int, int> m;
	for (int i = 0; i < size; ++i)
	{
		int cur = nums[i];
		int v = target - cur;
		
		if (m.find(v) != m.end() && m[v] != i)
			return {m[v], i};
		m[cur] = i;
	}
	return { -1, -1 };
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	if (matrix.size() <= 0) return {};
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<int> spiral(rows*cols);
	int u = 0, d = rows - 1, l = 0, r = cols - 1, k = 0;
	while (true) {
		for (int col = l; col <= r; ++col)
			spiral[k++] = matrix[u][col];
		if (++u > d) break;

		for (int row = u; row <= d; ++row)
			spiral[k++] = matrix[row][r];
		if (--r < l) break;

		for (int col = r; col >= l; --col)
			spiral[k++] = matrix[d][col];
		if (--d < u) break;

		for (int row = d; row >= u; --row)
			spiral[k++] = matrix[row][l];
		if (++l > r) break;
	}

	return spiral;
}


void printVecotr(const vector<int> &v)
{
	printf("vector is : ");
	for (auto &i : v)
	{
		printf("%d ", i);
	}
	printf("\n");
}

string addBinary(string a, string b) {
	if (a.empty() || b.empty())
		return "";

	string *strL = NULL;
	string *strS = NULL;
	if (a.length() > b.length())
	{
		strL = &a;
		strS = &b;
	}
	else
	{
		strL = &b;
		strS = &a;
	}

	string s(strL->length(), '0');
	char next_flag = 0;
	auto rL = strL->rbegin();
	auto rS = strS->rbegin();
	auto rs = s.rbegin();
	for (int i = 0; i < strL->length(); ++i)
	{
		char cur = 0;
		if (i < strS->length())
		{
			cur = *rS + *rL - *rs + next_flag;
			++rS;
		}
		else
		{
			cur = *rL + next_flag;
		}
		if (cur > '1')
		{
			cur -= 2;
			next_flag = 1;
		}
		else
			next_flag = 0;
		*rs = cur;
		++rs;
		++rL;

	}
	if (next_flag != 0)
	{
		s.resize(s.length() + 1);
		string s2((s.length() + 1), 0);
		std::copy(s.begin(), s.end(), ++s2.begin());
		s2[0] = '1';
		return s2;
	}
	
	return s;
}

int main()
{
	int a[] = { 'a', '1', '0' };
	auto v2 = addBinary("101", "1");
	printf("ret is %s \n", v2.c_str());
	system("pause");
}
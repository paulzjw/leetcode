//https://leetcode-cn.com/problems/contains-duplicate/description/
#include "Print.h"

int singleNumber(vector<int>& nums) {
	if (nums.empty())
		return -1;
	int v = nums[0];
	for (size_t i = 1; i < nums.size(); ++i)
	{
		v ^= nums[i];
	}
	return v;
}

int main()
{
	vector<int> nums = { 4,1,2,1,2 };
	auto ret = singleNumber(nums);
	print(ret);
	system("pause");
}


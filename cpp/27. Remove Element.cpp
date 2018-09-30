//https://leetcode-cn.com/problems/remove-element/description/
#include "Print.h"

//int removeElement(vector<int>& nums, int val) {
//	int k = 0;
//	for (int i = 0; i < nums.size(); ++i) {
//		if (nums[i] != val) {
//			nums[k] = nums[i];
//			++k;
//		}
//	}
//	return k;
//}

int removeElement(vector<int>& nums, int val) {
	int s = 0;
	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != val)
		{
			nums[s] = nums[i];
			++s;
		}
	}
	return s;
}


int main()
{
	vector<int> vi{2 , 2 , 4, 1, 6, 7};
	auto v = removeElement(vi, 1);
	print(v);
	system("pause");
}


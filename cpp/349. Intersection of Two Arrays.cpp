//https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
#include "Print.h"

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.empty() || nums2.empty())
		return {};
	
	if (nums1.size() > nums2.size())
		swap(nums1, nums2);

	unordered_set<int> is(nums1.begin(), nums1.end());
	vector<int> v;
	v.reserve(nums1.size());
	//for (auto i : nums1)
	//{
	//	is.insert(i);
	//}

	for (auto j : nums2)
	{
		if (is.find(j) != is.end())
		{
			is.erase(j);
			v.push_back(j);
			if (is.empty())
				break;
		}
	}

	return v;
}

int main()
{
	vector<int> nums = { 9,4,9,8,4 };
	vector<int> nums2 = { 4,9,5 };
	auto ret = intersection(nums, nums2);
	print(ret);
	system("pause");
}


//https://leetcode-cn.com/problems/contains-duplicate/description/
#include "Print.h"

bool containsDuplicateMyself(vector<int>& nums) {
	unordered_set<int> s;
	for (int i : nums)
	{
		if (s.find(i) != s.end())
		{
			return true;
		}
		s.insert(i);
	}
	return false;
}

// O(nlogn), 24ms
bool containsDuplicate(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] == nums[i - 1]) {
			return true;
		}
	}

	return false;
}

// ok, 28ms
bool containsDuplicate3(vector<int>& nums) {
	map<int, int> m;
	for (int i = 0; i < nums.size(); ++i) {
		if (m.find(nums[i]) != m.end()) {
			return true;
		}

		m[nums[i]] = 1;
	}

	return false;
}

// ok, O(n^2), 1600+ms
bool containsDuplicate2(vector<int>& nums) {
	vector<int> v;
	for (int i = 0; i < nums.size(); ++i) {
		if (find(v.begin(), v.end(), nums[i]) != v.end()) {
			return true;
		}

		v.push_back(nums[i]);
	}

	return false;
}

// space is too large, O(n)
bool containsDuplicate1(vector<int>& nums) {
	// INT_MAX -- 2147483647, INT_MIN -- -2147483648
	// 2147483647 + 2147483648 = 4294967295
	// store with bit, need about 512M, 4294967295 / 8 / 1024 / 1024 = 511M
	char bit_map[512 * 1024 * 1024] = { 0 };
	for (int i = 0; i < nums.size(); ++i) {
		long long int v = (long long int)nums[i] + INT_MAX;
		long long int byte_pos = v / 8, bit_pos = v % 8;
		int bit_check = 1 << bit_pos;
		if ((bit_map[byte_pos] & bit_check) != 0) {
			return true;
		}

		bit_map[byte_pos] |= bit_check;
	}

	return false;
}

int main()
{
	vector<int> nums = { 1, 1 };
	auto ret = containsDuplicate(nums);
	print(ret);
	system("pause");
}


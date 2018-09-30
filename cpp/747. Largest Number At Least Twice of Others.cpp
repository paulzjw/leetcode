//747. 至少是其他数字两倍的最大数
//747. Largest Number At Least Twice of Others

//In a given integer array nums, there is always exactly one largest element.
//
//Find whether the largest element in the array is at least twice as much as every other number in the array.
//
//If it is, return the index of the largest element, otherwise return -1.

//Scan through the array to find the unique largest element `m`, keeping track of it's index `maxIndex`. 
//Scan through the array again. If we find some `x != m` with `m < 2*x`, we should return `-1`. Otherwise, we should return `maxIndex`.


#include <stdio.h>
#include <vector>

using namespace std;

inline bool isGreatThanDouble(int max, int sec)
{
	return max >= sec * 2;
}

int dominantIndex(vector<int>& nums) {
	int len = nums.size();
	if (len == 1)
		return 0;

	int maxIndex = 0;
	int max = nums[0];
	int sec = nums[1];
	if (max < sec)
	{
		++maxIndex;
		max = sec;
		sec = nums[0];
	}
	if (len == 2)
	{
		return sec * 2 <= max ? maxIndex : -1;
	}

	for (int i = maxIndex + 1; i < len; ++i)
	{
		int cur = nums[i];
		if (cur > max)
		{
			sec = max;
			max = cur;
			maxIndex = i;
		}
		else if (cur > sec && cur <= max)
		{
			sec = cur;
		}
	}
	return sec * 2 <= max ? maxIndex : -1;
}

int main()
{
	std::vector<int> v{ 1, 2, 3, 7 };
	int index = dominantIndex(v);
	printf("max index is %d\n", index);
	system("pause");
}
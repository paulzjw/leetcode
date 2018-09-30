#include "Print.h"

//遍历加二分查找
vector<int> twoSum1(vector<int>& numbers, int target) {
	if (numbers.size() < 2)
		return {};
	
	vector<int> v;
	v.reserve(2);
	size_t start = 0;
	size_t end = numbers.size() - 1;

	for (; start < numbers.size(); ++start)
	{
		int cur = numbers[start];
		int tgt = target - cur;
		size_t left = start + 1;
		size_t right = end;
		
		while (left <= right)
		{
			size_t mid = (left + right) / 2;
			if (numbers[mid] < tgt)
				left = mid + 1;
			else if (numbers[mid] > tgt)
				right = mid - 1;
			else
			{
				v.push_back(start + 1);
				v.push_back(mid + 1);
				return v;
			}
		}
	}

	return v;
}

// fastest  o(n) 遍历
vector<int> twoSum(vector<int>& numbers, int target) {
	int i, j, n;
	vector<int> a;
	n = numbers.size();
	i = 0; j = n - 1;
	for (int k = 0; k<n; k++)
	{
		if (numbers[i] + numbers[j] == target)
		{
			a.push_back(i + 1);
			a.push_back(j + 1);
			break;
		}
		else if (numbers[i] + numbers[j]>target)
			j--;
		else
			i++;
	}
	return a;
}

int main()
{
	vector<int> v{1, 2 , 4, 8 };

	auto ret = twoSum(v, 6);
	print(ret);
	system("pause");
}


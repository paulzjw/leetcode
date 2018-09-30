//https://leetcode-cn.com/problems/spiral-matrix/description/

#include <stdio.h>
#include <vector>

using namespace std;

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

//vector<int> spiralOrder(vector<vector<int>>& matrix) {
//	int x = 0;
//	int y = 0;
//
//	vector<int> v;
//	if (matrix.empty())
//		return v;
//
//	int up = 0, down = matrix.size();
//	int left = 0, right = matrix[0].size();
//
//	v.reserve(down * right);
//
//	enum Direct {d_right, d_down, d_left, d_up};
//	Direct direct = d_right;
//
//	while (x >= up && x < down && y >= left && y < right)
//	{
//		switch (direct)
//		{
//		case d_right:
//		{
//			v.push_back(matrix[x][y]);
//			++y;
//			if (y == right)
//			{
//				direct = d_down;
//				--y;
//				++x;
//				if (x == down)
//					return v;
//				++up;
//			}
//		}
//		break;
//		case d_down:
//		{
//			v.push_back(matrix[x][y]);
//			++x;
//			if (x == down)
//			{
//				direct = d_left;
//				--x;
//				--y;
//				if (y < left)
//					return v;
//				--right;
//			}
//		}
//		break;
//		case d_left:
//		{
//			v.push_back(matrix[x][y]);
//			--y;
//			if (y < left)
//			{
//				direct = d_up;
//				++y;
//				--x;
//				if (x < up)
//					return v;
//				--down;
//			}
//		}
//		break;
//		case d_up:
//		{
//			v.push_back(matrix[x][y]);
//			--x;
//			if (x < up)
//			{
//				direct = d_right;
//				++x;
//				++y;
//				if (y == right)
//					return v;
//				++left;
//
//			}
//		}
//		break;
//		default:
//			break;
//		}
//	}
//	return v;
//}

void printVecotr(const vector<int> &v)
{
	printf("vector is : ");
	for (auto &i : v)
	{
		printf("%d ", i);
	}
	printf("\n");
}

int main()
{
	vector<vector<int>> v
	{
		}
	;
	auto v2 = spiralOrder(v);
	printVecotr(v2);
	system("pause");
}
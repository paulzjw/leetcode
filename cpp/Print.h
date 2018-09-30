#pragma once

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <queue>

#include <unordered_map>
#include <unordered_set>

using namespace std;

inline void print(bool v)
{
	printf("bool is : %s\n", v ? "true": "false");
}

inline void print(int v)
{
	printf("int is : %d\n", v);
}

template<size_t size>
inline void print(int (&arr)[size])
{
	printf("array is : ");
	for (size_t i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

inline void print(const string &s)
{
	printf("string is : %s\n", s.c_str());
}

inline void print(const vector<int> &v)
{
	printf("vector is : ");
	for (auto &i : v)
	{
		printf("%d ", i);
	}
	printf("\n");
}


inline void print(const list<int> &v)
{
	printf("list is : ");
	for (auto &i : v)
	{
		printf("%d ", i);
	}
	printf("\n");
}

//template<typename T>
//void print(T t)
//{
//
//}
//

class Print
{
public:
	Print();
	~Print();
};


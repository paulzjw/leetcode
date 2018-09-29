//https://leetcode-cn.com/problems/isomorphic-strings/description/
#include <stdio.h>
#include <unordered_map>

using namespace std;

bool isIsomorphic1(string s, string t) {
	unordered_map<char, char> m;
	unordered_map<char, char> rm;
	for (size_t i = 0; i < s.length(); ++i)
	{
		m.insert(make_pair(s[i], t[i]));
		auto iter = m.find(s[i]);
		if (iter == m.end() || iter->second != t[i])
			return false;

		rm.insert(make_pair(t[i], s[i]));
		auto iter2 = rm.find(t[i]);
		if (iter2 == rm.end() || iter2->second != s[i])
			return false;
	}
	return true;
}


//fastest 
bool isIsomorphic(string s, string t) {
	int m1[256] = { 0 }, m2[256] = { 0 }, n = s.size();
	for (int i = 0; i < n; ++i) {
		if (m1[s[i]] != m2[t[i]]) return false;
		m1[s[i]] = i + 1;
		m2[t[i]] = i + 1;
	}
	return true;
}

int main()
{
	auto v = isIsomorphic("aa",	"ab");
	printf("ret is %s\n", v ? "true" : "false");
	system("pause");
}
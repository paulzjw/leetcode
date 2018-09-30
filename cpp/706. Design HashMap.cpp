https://leetcode-cn.com/problems/design-hashmap/description/
#include "Print.h"

class MyHashMap {
public:
	/** Initialize your data structure here. */
	MyHashMap() {
		for (int i = 0; i < 10000; ++i)
			for (int j = 0; j < 100; ++j)
				buckets[i][j] = -1;
	}

	inline int hash(int key)
	{
		return key % 10000;
	}

	inline int index(int key)
	{
		return key / 10000;
	}

	/** value will always be positive. */
	void put(int key, int value) {
		int hash_code = hash(key);
		int hash_index = index(key);
		buckets[hash_code][hash_index] = value;
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		int hash_code = hash(key);
		int hash_index = index(key);
		return buckets[hash_code][hash_index];
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		int hash_code = hash(key);
		int hash_index = index(key);
		buckets[hash_code][hash_index] = -1;
	}

	int buckets[10000][100];
};

int main()
{
	MyHashMap *h = new MyHashMap();
	MyHashMap &hashMap = *h;
	hashMap.remove(65513);
	print(hashMap.get(16290));
	print(hashMap.get(1));            // 返回 1
	print(hashMap.get(3));            // 返回 -1 (未找到)
	hashMap.put(2, 1);         // 更新已有的值
	print(hashMap.get(2));            // 返回 1 
	hashMap.remove(2);         // 删除键为2的数据
	print(hashMap.get(2));            // 返回 -1 (未找到) 
	system("pause");
}


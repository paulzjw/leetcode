//https://leetcode-cn.com/problems/design-hashset/description/
#include "Print.h"

class MyHashSet {
public:
	/** Initialize your data structure here. */
	MyHashSet() {
		memset(buckets, 0, 10000 * 100);
	}

	inline int hash(int key)
	{
		return key % 10000;
	}

	inline int index(int key)
	{
		return key / 10000;
	}

	void add(int key) {
		int hash_code = hash(key);
		int hash_index = index(key);
		buckets[hash_code][hash_index] = true;
	}

	void remove(int key) {
		int hash_code = hash(key);
		int hash_index = index(key);
		buckets[hash_code][hash_index] = false;
	}

	/** Returns true if this set did not already contain the specified element */
	bool contains(int key) {
		int hash_code = hash(key);
		int hash_index = index(key);
		return buckets[hash_code][hash_index];
	}

	bool buckets[10000][100];
};


int main()
{
	MyHashSet *h = new MyHashSet();
	MyHashSet &hashSet = *h;
	hashSet.add(10000 * 100);
	hashSet.add(1);
	hashSet.add(2);
	print (hashSet.contains(1));    // ���� true
	print(hashSet.contains(3));    // ���� false (δ�ҵ�)
	hashSet.add(2);
	print(hashSet.contains(2));    // ���� true
	hashSet.remove(2);
	print(hashSet.contains(2));    // ����  false (�Ѿ���ɾ��)
	system("pause");
}


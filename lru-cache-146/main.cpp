#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

	LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
	int get(int key) Return the value of the key if the key exists, otherwise return -1.
	void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the
	cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.
*/
struct CacheNode {
	CacheNode* prev;
	CacheNode* next;
	int value;
	int mapKey;

	CacheNode() : prev(nullptr), next(nullptr), value(-1), mapKey(-1) {}
};

class LRUCache {
public:
	std::map<int, CacheNode*> mp;
	CacheNode* head;
	CacheNode* tail;
	const int size;

    LRUCache(int capacity) : size(capacity), head(nullptr), tail(nullptr) {}

    int get(int key) 
	{
		auto found = mp.find(key);
        if (found != mp.end()) 
		{
			CacheNode* node = found->second;
			if (node == head) return node->value;
			if (node == tail)
			{
				node->prev->next = nullptr;
				tail = node->prev;
			}
			else
			{
				node->prev->next = node->next;
				node->next->prev = node->prev;
			}
			head->prev = node;
			node->next = head;
			head = node;
			return node->value;
		}
		return -1;
    }
    
    void put(int key, int value) 
	{
        auto found = mp.find(key);
		if (found != mp.end())
		{
			found->second->value = value;
			get(key);
		}
		else 
		{
			CacheNode* node = new CacheNode();
			node->mapKey = key;
			node->value = value;
			if (mp.empty())
			{
				head = node;
				tail = node;
			}
			else if (mp.size() == size)
			{
				mp.erase(tail->mapKey);
				if (tail->prev)
				{
					tail = tail->prev;
					if (tail->next && tail->next != tail) 
					{
						delete tail->next;
					}
				}
				tail->next = nullptr;
			}
			if (head)
			{
				head->prev = node;
				node->next = head;
			}
			head = node;
			mp[key] = node;
		}
    }
};
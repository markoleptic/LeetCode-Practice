#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif
#include <random>
/**
Implement the RandomizedSet class:

	RandomizedSet() Initializes the RandomizedSet object.
	bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present,
false otherwise. bool remove(int val) Removes an item val from the set if present. Returns true if the item was present,
false otherwise. int getRandom() Returns a random element from the current set of elements (it's guaranteed that at
least one element exists when this method is called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.
*/

class RandomizedSet
{
public:
	RandomizedSet() : gen(rd()) {}

	bool insert(int val)
	{
		if (mapSet.contains(val))
		{
			return false;
		}
		mapSet[val] = true;
		return true;
	}

	bool remove(int val)
	{
		if (!mapSet.contains(val))
		{
			return false;
		}
		mapSet.erase(val);
		return true;
	}

	int getRandom()
	{
		std::uniform_int_distribution<int> distribution(0, mapSet.size() - 1);
		auto it = std::next(mapSet.begin(), distribution(gen));
		return (*it).first;
	}

private:
	map<int, bool> mapSet;
	std::random_device rd;
	std::mt19937 gen;
	int size = 0;
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&RandomizedSet::insert);
}
#endif
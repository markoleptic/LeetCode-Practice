#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps
and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

	TimeMap() Initializes the object of the data structure.
	void set(String key, String value, int timestamp) Stores the key key with the value value at the given time
timestamp. String get(String key, int timestamp) Returns a value such that set was called previously, with
timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest
timestamp_prev. If there are no values, it returns "".

*/
class TimeMap
{
public:
	TimeMap() {}

	void set(string key, string value, int timestamp) { timeMap[key].insert({timestamp, value}); }

	string get(string key, int timestamp)
	{
		if (timeMap.contains(key))
		{
			if (auto it = timeMap[key].upper_bound(timestamp); it != timeMap[key].begin())
			{
				return std::prev(it)->second;
			}
		}
		return "";
	}

private:
	map<string, map<int, string>> timeMap;
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&TimeMap::set);
}
#endif
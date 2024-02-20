#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array
prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course
ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.
*/

class Solution
{
    public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
	{
		vector<vector<int>> adjacent(numCourses, vector<int>());
		vector<int> degree(numCourses, 0);
		for (const auto& prereq : prerequisites)
		{
			int course = prereq[0];
			int prereqToCourse = prereq[1];
			adjacent[course].push_back(prereqToCourse);
			degree[course]++;
		}
		// queue with courses with 0 indegree (can be taken immediately)
		queue<int> q;
		for (int i = 0; i < numCourses; i++)
		{
			if (degree[i] == 0) q.push(i);
		}
		while (!q.empty())
		{
			int current = q.front(); q.pop();
			// iterate through adjacency list
			for (auto adj : adjacent[current])
			{
				// decrement the indegree
				degree[adj]--;
				if (degree[adj] == 0)
				{
					// course can be taken immediately
					q.push(adj);
				}
			}
			// decrement number of courses, as we've processed a course
			numCourses--;
		}
		return numCourses == 0; 
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::canFinish);
}
#endif
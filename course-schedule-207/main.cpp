#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

static void printDeps(map<int, vector<int>> map)
{
	for (auto elem = map.begin(); elem != map.end(); ++elem)
	{
		int numDeps = (*elem).second.size();
		cout << (*elem).first << ": ";
		for (int dep = 0; dep < numDeps; ++dep)
		{
			cout << (*elem).second[dep] << " ";
		}
		cout << endl;
	}
}

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
	bool hasCycle(const vector<vector<int>> &graph, vector<int> &visited, int node)
	{
		if (visited[node] == 1)
			return true;
		if (visited[node] == 2)
			return false;
		// Mark as visiting
		visited[node] = 1;
		for (int neighbor : graph[node])
		{
			if (hasCycle(graph, visited, neighbor))
			{
				// Propagate cycle detection
				return true;
			}
		}
		// Mark as visited
		visited[node] = 2;
		// No cycle detected
		return false;
	}
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
	{
		vector<vector<int>> graph(numCourses);
		for (const auto &prereq : prerequisites)
		{
			graph[prereq[0]].push_back(prereq[1]);
		}

		// 0: not visited, 1: visiting, 2: visited
		vector<int> visited(numCourses, 0); 

		for (int i = 0; i < numCourses; ++i)
		{
			if (visited[i] == 0 && hasCycle(graph, visited, i))
			{
				return false;
			}
		}

		return true; 
		
		// queue<int> q;
		// map<int, bool> visited;
		// map<int, vector<int>> data;

		// for (int i = 0; i < prerequisites.size(); ++i)
		// {
		// 	int classID = prerequisites[i][0];
		// 	int prereq = prerequisites[i][1];
		// 	data[classID].push_back(prereq);
		// 	q.push(classID);
		// }
		// while (!q.empty())
		// {
		// 	int classID = q.front();
		// 	q.pop();

		// 	vector<int> temp =  data[classID];
		// 	for (int prereq : temp)
		// 	{
		// 		if (classID == prereq) return false;
		// 		if (data.contains(prereq) && !visited[prereq])
		// 		{
		// 			q.push(prereq);
		// 			vector<int> preprereqs = data[prereq];
		// 			for (int k = 0; k < preprereqs.size(); ++k)
		// 			{
		// 				if (classID == preprereqs[k]) return false;
		// 				data[classID].push_back(preprereqs[k]);
		// 			}
		// 		}
		// 		visited[prereq] = true;
		// 	}
		// }

		// printDeps(data);
		// return true;
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
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> graph[2001];
		vector<int> degree(2001, 0);

		for (int i = 0; i < prerequisites.size(); i++) {
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
			degree[prerequisites[i][0]]++;
		}

		queue<int> q;
		for (int i = 0; i < numCourses; i++)
			if (degree[i] == 0)
				q.push(i);

		vector<int> answer;
		while (!q.empty()) {
			int front = q.front();
			q.pop();
			answer.push_back(front);

			for (int i : graph[front]) {
				degree[i]--;
				if (degree[i] == 0)
					q.push(i);
			}
		}

		return answer.size() == numCourses;
    }
};

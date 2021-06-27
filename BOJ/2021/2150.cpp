#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> graph[10001], rev_graph[10001];

vector<vector<int>> groups(10001);
stack<int> nodes;
bool check[10001];
int groupsCount = 0;

void dfs(int index)
{
	if (check[index])
		return;

	check[index] = true;
	for (int i = 0; i < graph[index].size(); i++)
		dfs(graph[index][i]);

	nodes.push(index); // 탐색이 종료되면 정점 저장
}

void rev_dfs(int index)
{
	if (check[index])
		return;

	check[index] = true;
	groups[groupsCount].push_back(index);
	for (int i = 0; i < rev_graph[index].size(); i++)
		rev_dfs(rev_graph[index][i]);
}

int main()
{
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		rev_graph[b].push_back(a);
	}

	for (int i = 1; i <= V; i++)
		if (!check[i])
			dfs(i);

	memset(check, false, sizeof(check));
	while (!nodes.empty()) {
		if (!check[nodes.top()]) {
			rev_dfs(nodes.top());

			sort(groups[groupsCount].begin(), groups[groupsCount].end());
			groupsCount++;
		}

		nodes.pop();
	}

	sort(groups.begin(), groups.begin() + groupsCount);

	cout << groupsCount << '\n';
	for (int i = 0; i < groupsCount; i++) {
		for (int j = 0; j < groups[i].size(); j++)
			cout << groups[i][j] << ' ';
		cout << "-1\n";
	}
}
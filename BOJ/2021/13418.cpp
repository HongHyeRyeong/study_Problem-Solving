#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> graph; 
vector<int> parent;

int Find(int v)
{
	if (parent[v] != v)
		parent[v] = Find(parent[v]);
	return parent[v];
}

int GetAnswer(bool min)
{
	for (int i = 0; i <= n; i++)
		parent[i] = i;

	if (min)
		sort(graph.begin(), graph.end());
	else
		sort(graph.rbegin(), graph.rend());

	int answer = 0;
	for (int i = 0; i <= m; i++)
	{
		int parentA = Find(graph[i].second.first), parentB = Find(graph[i].second.second);
		if (parentA != parentB)
		{
			parent[parentA] = parentB;
			answer += graph[i].first;
		}
	}

	return answer * answer;
}

int main()
{
	cin >> n >> m;
	for (int i = 0, a, b, c; i <= m; i++)
	{
		cin >> a >> b >> c;
		graph.push_back({ c == 0 ? 1 : 0, {a,b} });
	}

	parent.resize(n + 1);
	cout << GetAnswer(false) - GetAnswer(true);
}
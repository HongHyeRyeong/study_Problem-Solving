#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() 
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> graph[32001];
	vector<int> degree(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		degree[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++)
		if (degree[i] == 0)
			pq.push(i);

	while (!pq.empty()) {
		int top = pq.top();
		cout << top << ' ';
		pq.pop();

		for (int i : graph[top]) {
			degree[i]--;
			if (degree[i] == 0)
				pq.push(i);
		}
	}
}
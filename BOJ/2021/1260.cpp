#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

vector<int> v[1001];
bool check[1001];

void dfs(int index)
{
	if (check[index])
		return;

	cout << index << " ";
	check[index] = true;

	for (int i = 0; i < v[index].size(); ++i)
		dfs(v[index][i]);
}

void bfs(int index)
{
	queue<int> q;
	q.push(index);
	check[index] = true;

	while (!q.empty()) {
		int p = q.front();
		q.pop();

		cout << p << " ";

		for (int i = 0; i < v[p].size(); ++i) {
			int next = v[p][i];

			if (!check[next]) {
				q.push(next);
				check[next] = true;
			}
		}
	}
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; ++i) {
		int a,b;
		cin >> a>>b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());

	dfs(V);

	cout << '\n';
	for (int i = 0; i < 1001; ++i)
		check[i] = false;
	
	bfs(V);
}
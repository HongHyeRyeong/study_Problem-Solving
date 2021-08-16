#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V1, V2;
vector<pair<int, int>> graph[10001];

bool bfs(int weightLimit)
{
	queue<int> q;
	bool ck[10001]{};

	q.push(V1);
	ck[V1] = true;
	while (!q.empty()) {
		int tv = q.front();
		q.pop();

		if (tv == V2)
			return true;

		for (int i = 0; i < graph[tv].size(); ++i) {
			int nv = graph[tv][i].first, nw = graph[tv][i].second;
			if (!ck[nv] && nw >= weightLimit) {
				q.push(nv);
				ck[nv] = true;
			}
		}
	}
	return false;
}

int main(void)
{
	cin >> N >> M;

	int start = 1e9, end = 0, mid = 0;
	for (int i = 0, A, B, C; i < M; ++i) {
		cin >> A >> B >> C;
		graph[A].push_back({ B,C });
		graph[B].push_back({ A,C });

		start = min(start, C);
		end = max(end, C);
	}

	cin >> V1 >> V2;

	while (start <= end) {
		mid = (start + end) / 2;

		if (bfs(mid))
			start = mid + 1;
		else
			end = mid - 1;
	}
	cout << end;
}
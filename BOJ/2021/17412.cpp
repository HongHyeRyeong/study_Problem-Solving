#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int c[401][401];
int f[401][401];
vector<int> map[401];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, P;
	cin >> N >> P;
	while (P--) {
		int u, v;
		cin >> u >> v;

		map[u].push_back(v);
		map[v].push_back(u);
		c[u][v] = 1;
		c[v][u] = 0;
	}

	int maximumFlow = 0, s = 1, t = 2;
	while (true) {
		int visit[401]{};
		fill(visit, visit + 401, -1);

		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int front = q.front();
			q.pop();

			for (int i = 0; i < map[front].size(); i++) {
				int next = map[front][i];
				if (c[front][next] - f[front][next] > 0 && visit[next] == -1) {
					q.push(next);
					visit[next] = front;

					if (next == t)
						break;
				}
			}
		}

		// ���� ��ΰ� ���ٸ� Ż��
		if (visit[t] == -1)
			break;

		int flow = 1e9;

		// ���� ���� ã��
		for (int i = t; i != s; i = visit[i])
			flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);

		// ���� ���� �뷮��ŭ ���� �긮��
		for (int i = t; i != s; i = visit[i]) {
			f[visit[i]][i] += flow;
			f[i][visit[i]] -= flow;
		}

		maximumFlow += flow;
	}

	cout << maximumFlow;
}
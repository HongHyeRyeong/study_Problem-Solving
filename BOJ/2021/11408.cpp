#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[802];
int s = 0, t = 801;
int ca[802][802], fl[802][802], cost[802][802];

int main()
{
	int n, m;
	cin >> n >> m;

	// Source�� ��� ����� ����
	for (int i = 1; i <= n; i++) {
		v[s].push_back(i);
		v[i].push_back(s);
		ca[s][i] = 1; // �뷮�� �����⸸ �߰�
	}

	// �ϰ� Sink ����� ����
	for (int i = 1; i <= m; i++) {
		v[t].push_back(i + 400);
		v[i + 400].push_back(t);
		ca[i + 400][t] = 1; // �뷮�� �����⸸ �߰�
	}

	// ����� �� ����
	for (int i = 1; i <= n; i++) {
		int cnt;
		cin >> cnt;

		for (int j = 0; j < cnt; j++) {
			int num, money;
			cin >> num >> money;

			// ����� �� ����� ����
			v[i].push_back(num + 400);
			v[num + 400].push_back(i);

			// �뷮�� �����⸸ �߰�
			ca[i][num + 400] = 1;

			// ����� �����
			cost[i][num + 400] = money;
			cost[num + 400][i] = -money;
		}
	}

	// MCMF
	int ans = 0, result = 0;
	while (1) {
		int pre[802]; // ���� ��� ����
		int dist[802]; // s�κ��� �ִܰŸ�
		fill(dist, dist + 802, 2e9);
		fill(pre, pre + 802, -1);

		queue<int> q;
		bool visit[802]{};

		q.push(s);
		visit[s] = true;
		dist[s] = 0;

		while (!q.empty()) {
			int node = q.front(); q.pop();
			visit[node] = false;

			for (auto next : v[node]) {
				if (dist[next] > dist[node] + cost[node][next] && ca[node][next] > fl[node][next]) {
					dist[next] = dist[node] + cost[node][next];
					pre[next] = node;
					if (!visit[next]) {
						visit[next] = true;
						q.push(next);
					}
				}
			}
		}

		// �ִ� ��ΰ� ���̻� ����
		if (pre[t] == -1)
			break;

		int flow = 2e9;
		for (int i = t; i != s; i = pre[i]) {
			flow = min(flow, ca[pre[i]][i] - fl[pre[i]][i]);
		}
		for (int i = t; i != s; i = pre[i]) {
			result += cost[pre[i]][i];
			fl[pre[i]][i] += flow;
			fl[i][pre[i]] -= flow;
		}
		ans += flow;
	}

	cout << ans << "\n" << result << "\n";
}
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int c[52][52]; // 흐르는 양
int f[52][52]; // 흐르고 있는 양
int visit[52];
vector<int> map[52];

// 애드몬드 카프 알고리즘
int maxFlow(int start, int end) 
{
	int ret = 0;

	while (true) {
		memset(visit, -1, sizeof(visit));

		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int front = q.front();
			q.pop();

			for (int i = 0; i < map[front].size(); i++) {
				int e = map[front][i];
				if (c[front][e] - f[front][e] > 0 && visit[e] == -1) {
					q.push(e);
					visit[e] = front;

					if (e == end)
						break;
				}
			}
		}

		if (visit[end] == -1)
			break;

		int flow = 1e9;
		for (int i = end; i != start; i = visit[i])
			flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);

		for (int i = end; i != start; i = visit[i]) {
			f[visit[i]][i] += flow;
			f[i][visit[i]] -= flow;
		}

		ret += flow;
	}

	return ret;
}

int getID(char c)
{
	if (c <= 'Z')
		return c - 'A';
	return c - 'a' + 26;
}

int main() 
{
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	int N; 
	cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b; 
		int w; 
		cin >> a >> b >> w;

		int A = getID(a), B = getID(b);

		map[A].push_back(B);
		map[B].push_back(A);
		c[A][B] += w;
		c[B][A] += w;
	}

	cout << maxFlow(0, 25);
}
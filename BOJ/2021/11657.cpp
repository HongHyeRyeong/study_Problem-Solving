#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> v[501];
	for (int i = 0, A, B, C; i < M; i++) {
		cin >> A >> B >> C;
		v[A].push_back({ B, C });
	}

	long long dist[501];
	fill(dist, dist + N + 1, 1e9);
	dist[1] = 0;

	bool flag = false;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (flag || dist[j] == 1e9)
				continue;

			for (auto& k : v[j]) {
				if (dist[j] + k.second < dist[k.first]) {
					dist[k.first] = dist[j] + k.second;

					if (i == N)
						flag = true;
				}
			}
		}

	if (flag)
		cout << -1;
	else {
		for (int i = 2; i <= N; i++)
			printf("%lld\n", dist[i] == 1e9 ? -1 : dist[i]);
	}
}
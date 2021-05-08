#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n, m, w;
		cin >> n >> m >> w;

		vector<pair<int, int>> v[501];
		for (int i = 0; i < m; ++i) {
			int s, e, t;
			cin >> s >> e >> t;
			v[s].push_back({ e, t });
			v[e].push_back({ s, t });
		}
		for (int i = 0; i < w; ++i) {
			int s, e, t;
			cin >> s >> e >> t;
			v[s].push_back({ e, -t });
		}

		int dist[501];
		fill(dist, dist + 501, 1e9);
		dist[1] = 0;

		bool flag = false;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				for (auto& k : v[j]) {
					if (dist[j] + k.second < dist[k.first]) {
						dist[k.first] = dist[j] + k.second;

						if (i == n)
							flag = true;
					}
				}
			}

		cout << (flag == true ? "YES\n" : "NO\n");
	}
}
#include <iostream> 
#include <queue>
using namespace std;

bool map[1000][1000], checked[1000][1000][2];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);

	int answer = 0;
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, { 0, 0 } });
	checked[0][0][0] = true;
	while (!q.empty()) {
		answer++;

		int size = q.size();
		while (size--) {
			int tx = q.front().second.second;
			int ty = q.front().second.first;
			int crash = q.front().first;
			q.pop();

			if (tx == m - 1 && ty == n - 1) {
				cout << answer;
				return 0;
			}

			int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
			for (int i = 0; i < 4; i++) {
				int nx = tx + dir[i][0], ny = ty + dir[i][1];

				if (nx < 0 || nx >= m || ny < 0 || ny >= n)
					continue;
				if (checked[ny][nx][crash])
					continue;
				if (map[ny][nx]) {
					if (crash)
						continue;
					q.push({ 1,{ny, nx} });
				}
				else
					q.push({ crash,{ny, nx} });

				checked[ny][nx][crash] = true;
			}
		}
	}

	cout << -1;
}
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;

	int map[1000][1000]{};
	bool check[1000][1000]{};
	queue<pair<int, int>> q;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				q.push({ i,j });
				check[i][j] = true;
			}
		}

	int answer = -1;
	while (!q.empty()) {
		++answer;

		int size = q.size();
		while (size--) {
			int ty = q.front().first, tx = q.front().second;
			q.pop();

			int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
			for (int i = 0; i < 4; i++) {
				int nx = tx + dir[i][0], ny = ty + dir[i][1];
				if (nx < 0 || nx >= M || ny < 0 || ny >= N)
					continue;
				if (check[ny][nx] || map[ny][nx] != 0)
					continue;

				q.push(make_pair(ny, nx));
				check[ny][nx] = true;
				map[ny][nx] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!map[i][j]) {
				cout << -1;
				return 0;
			}

	cout << answer;
}
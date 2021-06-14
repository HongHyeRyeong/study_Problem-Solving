#include <iostream>
#include <queue>
using namespace std;

int map[100][100][100]{};
bool check[100][100][100]{};

int main()
{
	int M, N, H;
	cin >> M >> N >> H;

	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < M; ++k) {
				cin >> map[i][j][k];

				if (map[i][j][k] == 1) {
					q.push({ i,{j,k} });
					check[i][j][k] = true;
				}
			}

	int answer = -1;
	while (!q.empty()) {
		++answer;

		int size = q.size();
		while (size--) {
			int tz = q.front().first;
			int ty = q.front().second.first;
			int tx = q.front().second.second;
			q.pop();

			int dir[9][3] = { {-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1} };
			for (int i = 0; i < 9; i++) {
				int nx = tx + dir[i][0], ny = ty + dir[i][1], nz = tz + dir[i][2];
				if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H)
					continue;
				if (check[nz][ny][nx] || map[nz][ny][nx])
					continue;

				q.push({ nz,{ny, nx} });
				check[nz][ny][nx] = true;
				map[nz][ny][nx] = 1;
			}
		}
	}

	for (int k = 0; k < H; k++)
		for (int j = 0; j < N; j++)
			for (int i = 0; i < M; i++)
				if (!map[k][j][i]) {
					cout << -1;
					return 0;
				}
	cout << answer;
}
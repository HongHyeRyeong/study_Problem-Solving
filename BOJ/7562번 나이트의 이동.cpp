#include <iostream>
#include <queue>
using namespace std;

bool ck[300][300];
int dir[8][2]{ {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}, {-2,-1} };

int main(void)
{
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		pair<int, int> p1, p2; // Ãâ¹ß, µµÂø
		cin >> p1.first >> p1.second >> p2.first >> p2.second;

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				ck[i][j] = false;

		queue<pair<pair<int, int>, int>> q;
		q.push({ p1, 0 });
		ck[p1.first][p1.second] = true;
		while (!q.empty()) {
			int tx = q.front().first.first;
			int ty = q.front().first.second;
			int cnt = q.front().second;
			q.pop();

			if (tx == p2.first && ty == p2.second) {
				cout << cnt << '\n';
				break;
			}

			for (int i = 0; i < 8; ++i) {
				int nx = tx+ dir[i][0], ny = ty + dir[i][1];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N)
					continue;

				if (!ck[nx][ny]) {
					q.push({ { nx,ny }, cnt + 1 });
					ck[nx][ny] = true;
				}
			}
		}
	}
}
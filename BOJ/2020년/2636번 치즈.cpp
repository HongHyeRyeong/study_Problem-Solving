#include <iostream>
using namespace std;

int N, M;
int time, piece, cnt;
bool map[100][100], ck[100][100];
int dir[4][2]{ {1,0},{-1,0},{0,1},{0,-1} };

void DFS(int x, int y)
{
	ck[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N)
			continue;

		if (map[ny][nx] && !ck[ny][nx]) {
			map[ny][nx] = false;
			ck[ny][nx] = true;
			cnt--;
			piece++;
		}
		else if (!map[ny][nx] && !ck[ny][nx])
			DFS(nx, ny);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j])
				cnt++;
		}

	while (cnt) {
		piece = 0;
		time++;
		DFS(0, 0);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				ck[i][j] = false;
	}
	cout << time << "\n" << piece;
}
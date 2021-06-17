#include <iostream>
using namespace std;

int N, M;
int time, piece, cnt;
bool map[100][100], check[100][100];
int dir[4][2]{ {1,0},{-1,0},{0,1},{0,-1} };

void DFS(int x, int y)
{
	check[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];

		if (nx < 0 || nx >= M || ny < 0 || ny >= N)
			continue;
		if (check[ny][nx])
			continue;

		if (map[ny][nx]) {
			cnt--;
			map[ny][nx] = false;
			check[ny][nx] = true;
		}
		else
			DFS(nx, ny);
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j])
				cnt++;
		}

	while (cnt) {
		time++;
		piece = cnt;

		DFS(0, 0);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				check[i][j] = false;
	}

	cout << time << "\n" << piece;
}
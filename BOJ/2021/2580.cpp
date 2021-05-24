#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> emptyPoint;
int board[9][9];

void dfs(int index)
{
	if (index == emptyPoint.size()) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j)
				cout << board[i][j] << ' ';
			cout << '\n';
		}
		exit(0);
	}

	for (int i = 1; i <= 9; ++i) {
		pair<int, int> point = emptyPoint[index];
		bool flag = true;

		int dir[9][2]{ {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2} };
		for (int j = 0; j < 9; ++j) {
			if (board[point.first][j] == i || board[j][point.second] == i ||
				board[point.first / 3 * 3 + dir[j][0]][point.second / 3 * 3 + dir[j][1]] == i) {
				flag = false;
				break;
			}
		}

		if (flag) {
			board[point.first][point.second] = i;
			dfs(index + 1);
			board[point.first][point.second] = 0;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			cin >> board[i][j];

			if (board[i][j] == 0)
				emptyPoint.push_back({ i ,j });
		}

	dfs(0);
}
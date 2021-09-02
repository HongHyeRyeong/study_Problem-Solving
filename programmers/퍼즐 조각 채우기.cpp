#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Block {
	vector<vector<int>> v;
	int n, m;

	Block(int n, int m) : n(n), m(m), v(n, vector<int>(m)) {}

	Block Rotate() {
		Block b(m, n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				b.v[j][n - 1 - i] = v[i][j];
		return b;
	}

	int GetCnt() {
		int count = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (v[i][j])
					count++;
		return count;
	}
};

vector<Block> Extract(vector<vector<int>> board, bool flag)
{
	vector<Block> ret;
	int n = board.size(), m = board[0].size();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (board[i][j] != flag)
				continue;

			vector<pair<int, int>> block;
			queue<pair<int, int>> Q;
			int x_mn = 1e9, x_mx = -1e9;
			int y_mn = 1e9, y_mx = -1e9;

			block.push_back({ i, j });
			Q.push({ i, j });
			board[i][j] = !flag;
			while (Q.size()) {
				auto q = Q.front();
				Q.pop();

				x_mn = min(x_mn, q.first); x_mx = max(x_mx, q.first);
				y_mn = min(y_mn, q.second); y_mx = max(y_mx, q.second);

				int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
				for (int k = 0; k < 4; k++) {
					int nx = q.first + dir[k][0], ny = q.second + dir[k][1];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] != flag)
						continue;

					block.push_back({ nx, ny });
					Q.push({ nx, ny });
					board[nx][ny] = !flag;
				}
			}

			Block cur(x_mx - x_mn + 1, y_mx - y_mn + 1);
			for (auto& i : block)
				cur.v[i.first - x_mn][i.second - y_mn] = 1;
			ret.push_back(cur);
		}

	return ret;
}

bool IsEqual(Block& a, Block& b)
{
	if (a.GetCnt() != b.GetCnt())
		return false;

	Block t = a;
	for (int i = 0; i < 4; i++) {
		if (t.n == b.n && t.m == b.m && t.v == b.v)
			return true;
		t = t.Rotate();
	}

	return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
	int answer = 0;
	auto v1 = Extract(game_board, 0);
	auto v2 = Extract(table, 1);

	for (auto& i : v1) {
		for (int j = 0; j < v2.size(); j++) {
			if (IsEqual(i, v2[j])) {
				answer += i.GetCnt();
				v2.erase(v2.begin() + j);
				break;
			}
		}
	}

	return answer;
}
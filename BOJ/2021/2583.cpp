#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
bool map[100][100], check[100][100];

int dfs(int x, int y)
{
	if (0 > x || x >= M || 0 > y || y >= N)
		return 0;
	if (map[x][y] || check[x][y])
		return 0;

	check[x][y] = true;
	return dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1) + 1;
}

int main()
{
	cin >> M >> N >> K;
	while (K--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; ++i)
			for (int j = x1; j < x2; ++j)
				map[i][j] = true;
	}

	vector<int> v;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			if (!map[i][j] && !check[i][j]) {
				v.push_back(dfs(i, j));
			}

	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i : v)
		cout << i << ' ';
}
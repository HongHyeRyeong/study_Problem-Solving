#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> answer;

int N;
int map[25][25];
bool check[25][25];

int dfs(int x, int y)
{
	if (0 > x || x >= N || 0 > y || y >= N)
		return 0;
	if (check[x][y] || map[x][y] == 0)
		return 0;

	check[x][y] = true;
	return 	1 + dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%1d", &map[i][j]);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (map[i][j] == 1 && !check[i][j])
				answer.push_back(dfs(i, j));

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << '\n';
}
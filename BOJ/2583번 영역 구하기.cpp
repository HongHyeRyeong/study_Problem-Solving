#include <iostream>
#include <set>
using namespace std;

int N, M, K;
bool map[100][100], ck[100][100];

int DFS(int x, int y)
{
	if (x < 0 || x >= M || y < 0 || y >= N)
		return 0;
	if (map[y][x] || ck[y][x])
		return 0;
	ck[y][x] = true;
	return 1 + DFS(x + 1, y) + DFS(x - 1, y) + DFS(x, y + 1) + DFS(x, y - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	while (K--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = b; i < d; i++)
			for (int j = a; j < c; j++)
				map[i][j] = true;
	}

	multiset<int> s;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!map[i][j] && !ck[i][j])
				s.insert(DFS(j, i));

	cout << s.size() << "\n";
	for (int i : s)
		cout << i << " ";
}
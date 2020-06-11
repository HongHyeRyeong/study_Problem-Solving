#include <iostream>
#include <vector>
using namespace std;

int ans;
vector<int> v;
vector<bool> check, visited; // 방문, 재방문

void DFS(int start, int index)
{
	if (visited[index]) { // 재방문
		ans++;

		int temp = v[index];
		while (temp != index) {
			ans++;
			temp = v[temp];
		}
	}
	else {
		visited[index] = true;
		if (!check[v[index]]) {
			DFS(start, v[index]);
			check[index] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;

		ans = 0;
		v = vector<int>(N + 1, 0);
		check = vector<bool>(N + 1, false);
		visited = vector<bool>(N + 1, false);

		for (int i = 1; i <= N; i++)
			cin >> v[i];

		for (int i = 1; i <= N; i++) {
			if (!check[i]) {
				visited = vector<bool>(N + 1, false);
				DFS(i, i);
			}
		}
		cout << v.size() - ans - 1 << "\n";
	}
}
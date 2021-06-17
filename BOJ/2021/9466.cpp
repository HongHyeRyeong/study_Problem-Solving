#include <iostream>
#include <vector>
using namespace std;

int team;
vector<int> v;
vector<bool> check, visited; // 방문, 재방문

void DFS(int start, int index)
{
	if (visited[index]) {
		team++;

		int temp = v[index];
		while (temp != index) {
			team++;
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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		team = 0;
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

		cout << N - team << "\n";
	}
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 1e9;
int N, M, chooseChicken[13];
vector<pair<int, int>> house, chicken;

void dfs(int index, int count)
{
	if (index == M) {
		int dist = 0;
		for (pair<int, int> h : house) {
			int houseDist = 1e9;
			for (int i = 0; i < M; ++i)
				houseDist = min(houseDist,
					abs(chicken[chooseChicken[i]].first - h.first) + abs(chicken[chooseChicken[i]].second - h.second));
			dist += houseDist;
		}

		answer = min(answer, dist);
		return;
	}

	for (int i = count; i < chicken.size(); ++i) {
		chooseChicken[index] = i;
		dfs(index + 1, i + 1);
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			int temp;
			cin >> temp;

			if (temp == 1)
				house.push_back({ i,j });
			else if (temp == 2)
				chicken.push_back({ i,j });
		}

	dfs(0, 0);
	cout << answer;
}
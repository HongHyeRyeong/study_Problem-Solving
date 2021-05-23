#include <iostream>
using namespace std;

int answer = 1e9;
int N, arr[20][20], start[10];

void dfs(int index, int count)
{
	if (index == N / 2) {
		int link[10]{};
		for (int i = 0, index1 = 0, index2 = 0; i < N; ++i)
			start[index1] == i ? index1++ : link[index2++] = i;

		int t1 = 0, t2 = 0;
		for (int i = 0; i < N / 2; ++i)
			for (int j = i + 1; j < N / 2; ++j) {
				t1 += arr[start[i]][start[j]] + arr[start[j]][start[i]];
				t2 += arr[link[i]][link[j]] + arr[link[j]][link[i]];
			}

		if (abs(t1 - t2) < answer)
			answer = abs(t1 - t2);
		return;
	}

	for (int i = count; i < N; ++i) {
		start[index] = i;
		dfs(index + 1, i + 1);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> arr[i][j];

	dfs(0, 0);
	cout << answer;
}
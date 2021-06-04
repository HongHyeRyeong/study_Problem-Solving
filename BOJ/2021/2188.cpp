#include <iostream>
#include <vector>
using namespace std;

vector<int> cow[201];
int space[201];
bool ckeck[201];

bool dfs(int index)
{
	if (ckeck[index])
		return false;
	ckeck[index] = true;

	for (auto i : cow[index])
		if (!space[i] || dfs(space[i])) {
			space[i] = index;
			return true;
		}

	return false;
}

int main()
{
	int N, M, S;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> S;
		cow[i].resize(S);
		for (int j = 0; j < S; ++j)
			cin >> cow[i][j];
	}

	int answer = 0;
	for (int i = 1; i <= N; ++i) {
		fill(ckeck, ckeck + N, false);

		if (dfs(i))
			++answer;
	}
	cout << answer;
}
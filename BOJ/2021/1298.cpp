#include <iostream>
#include <vector>
using namespace std;

vector<int> notebook[101];
int student[1001];
bool check[101];

bool dfs(int index)
{
	if (check[index])
		return false;
	check[index] = true;

	for (auto nb : notebook[index])
		if (!student[nb] || dfs(student[nb])) {
			student[nb] = index;
			return true;
		}
	return false;
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		notebook[a].push_back(b);
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		fill(check, check + N, false);
		if (dfs(i))
			++ans;
	}
	cout << ans;
}
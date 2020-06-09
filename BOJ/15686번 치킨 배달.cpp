#include <iostream>
#include <vector>
using namespace std;

int ans = 1e10, N, M;
vector<pair<int, int>> home, chicken;

// M개 고르기
int number[50];
bool ck[50];

int dist(pair<int, int> p1, pair<int, int> p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void f(int index, int cnt)
{
	if (index == M) {
		int sum = 0;
		for (int i = 0; i < home.size(); ++i) {
			int min = 1e10;
			for (int j = 0; j < M; ++j) {
				int tmp = dist(home[i], chicken[number[j]]);
				if (tmp < min)
					min = tmp;
			}
			sum += min;
		}
		if (sum < ans)
			ans = sum;
		return;
	}

	for (int i = cnt; i < chicken.size(); ++i) {
		if (!ck[i]) {
			ck[i] = true;
			number[index] = i;
			f(index + 1, i + 1);
			ck[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> tmp;
			if (tmp == 1)
				home.push_back({ j,i });
			else if (tmp == 2)
				chicken.push_back({ j,i });
		}

	f(0, 0);
	cout << ans;
}
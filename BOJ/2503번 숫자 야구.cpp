#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<pair<string, pair<int, int>>> v(100);

bool f(int a, int b, int c)
{
	for (int i = 0; i < N; ++i) {
		int strike = 0, ball = 0;

		int tmp = v[i].first[0] - '0';
		if (tmp == a)
			strike++;
		else if (tmp == b || tmp == c)
			ball++;

		tmp = v[i].first[1] - '0';
		if (tmp == b)
			strike++;
		else if (tmp == a || tmp == c)
			ball++;

		tmp = v[i].first[2] - '0';
		if (tmp == c)
			strike++;
		else if (tmp == a || tmp == b)
			ball++;

		if (strike != v[i].second.first || ball != v[i].second.second)
			return false;
	}
	return true;
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> v[i].first >> v[i].second.first >> v[i].second.second;

	int ans = 0;
	for (int i = 1; i < 10; ++i)
		for (int j = 1; j < 10; ++j) {
			if (i == j)
				continue;
			for (int k = 1; k < 10; ++k) {
				if (i == k || j == k)
					continue;
				if (f(i, j, k))
					ans++;
			}
		}
	cout << ans;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
		if (p1.second == p2.second)
			return p1.first < p2.first;
		return p1.second < p2.second;
		});

	for (auto a : v)
		cout << a.first << " " << a.second << "\n";
}
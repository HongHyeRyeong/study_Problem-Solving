#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int dist(pair<int, int> p1, pair<int, int> p2) {
	return pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2);
}

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i].second >> p[i].first;

	sort(p.begin(), p.end(), [](pair<int, int> p1, pair<int, int> p2) {
		if (p1.second == p2.second)
			return p1.first < p2.first;
		return p1.second < p2.second;
		});

	set<pair<int, int>> s;
	s.insert(p[0]);
	s.insert(p[1]);

	int answer = dist(p[0], p[1]), start = 0;
	for (int i = 2; i < n; i++) {
		// y좌표가 answer 보다 큰 점 제외
		int x = p[i].second - p[start].second;
		while (start < i && x * x >= answer) {
			s.erase(p[start++]);
			x = p[i].second - p[start].second;
		}

		// x좌표가 (x좌표 ± answer) 거리 내에 있는 점 중 최단 거리를 answer로 갱신
		auto start = s.lower_bound({ p[i].first - sqrt(answer), -INF });
		auto end = s.upper_bound({ p[i].first + sqrt(answer), INF });
		for (auto j = start; j != end; j++)
			answer = min(answer, dist(p[i], *j));

		s.insert(p[i]);
	}
	cout << answer;
}
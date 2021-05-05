#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> gem(N);
	for (int i = 0; i < N; ++i)
		cin >> gem[i].first >> gem[i].second;
	sort(gem.begin(), gem.end());

	vector<int> bag(K);
	for (int i = 0; i < K; ++i)
		cin >> bag[i];
	sort(bag.begin(), bag.end());

	long long ans = 0;
	priority_queue<int> pq;
	for (int i = 0, j = 0; i < K; ++i) {
		while (j < N && gem[j].first <= bag[i]) {
			pq.push(gem[j++].second);
		}

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}
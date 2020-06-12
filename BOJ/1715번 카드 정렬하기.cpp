#include <iostream>
#include <queue>
using namespace std;

int num[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0, tmp; i < N; ++i) {
		cin >> tmp;
		pq.push(tmp);
	}

	int ans = 0;
	while (!pq.empty()) {
		int tmp = pq.top();
		pq.pop();

		if (!pq.empty()) {
			tmp += pq.top();
			pq.pop();

			ans += tmp;
			pq.push(tmp);
		}
	}
	cout << ans;
}
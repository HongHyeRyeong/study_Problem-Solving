#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		queue<pair<int, bool>> q;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if (i == m)
				q.push(make_pair(v[i], true));
			else
				q.push(make_pair(v[i], false));
		}

		sort(v.begin(), v.end());

		int result = 0;
		while (!q.empty()) {
			if (q.front().first == v.back()) {
				result++;
				v.pop_back();

				if (q.front().second) {
					cout << result << '\n';
					break;
				}
			}
			else 
				q.push(q.front());

			q.pop();
		}
	}
}
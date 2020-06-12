#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;

		vector<pair<int, int>> v(M);
		for (int i = 0; i < M; ++i)
			cin >> v[i].second >> v[i].first;
		sort(v.begin(), v.end());

		int ans = 0;
		bool ck[1001]{};
		for (int i = 0, j = N; i < M; ++i) {
			for (int j = v[i].second; j <= v[i].first; ++j) {
				if (!ck[j]) {
					ck[j] = true;
					ans++;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}
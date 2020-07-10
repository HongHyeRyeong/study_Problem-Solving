#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;

		long long ans = 1;
		for (int i = N + 1; i <= M; ++i)
			ans = (ans * i) / (i - N);
		cout << ans << '\n';
	}
}
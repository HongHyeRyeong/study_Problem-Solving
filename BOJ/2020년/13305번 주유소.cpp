#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> a(N - 1), b(N);
	for (int i = 0; i < N - 1; ++i)
		cin >> a[i];
	for (int i = 0; i < N; ++i)
		cin >> b[i];

	long long ans = 0;
	for (int i = 0, tmp = b[0]; i < N - 1; ++i) {
		ans += (long long)tmp * a[i];
		tmp = min(tmp, b[i + 1]);
	}
	cout << ans;
}
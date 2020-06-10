#include <iostream>
#include <vector>
using namespace std;

bool prime[4000001] = { true, true };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 2; i * i <= N; ++i)
		if (!prime[i])
			for (int j = i * i; j <= N; j += i)
				prime[j] = true;

	vector<int> v;
	for (int i = 0; i <= N; ++i)
		if (!prime[i])
			v.push_back(i);

	int ans = 0, sum = 0;
	int start = 0, end = 0;
	while (true) {
		if (sum >= N)
			sum -= v[start++];
		else if (end == v.size())
			break;
		else
			sum += v[end++];

		if (sum == N)
			ans++;
	}
	cout << ans;
}
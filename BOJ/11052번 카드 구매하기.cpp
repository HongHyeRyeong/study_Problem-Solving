#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int card[1001], dp[1001]{};
	for (int i = 1; i <= N; ++i)
		cin >> card[i];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = max(dp[i], dp[i - j] + card[j]);
	cout << dp[N];
}
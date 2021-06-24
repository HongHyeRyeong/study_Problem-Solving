#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int grape[10001];
	for (int i = 1; i <= n; ++i)
		cin >> grape[i];

	int dp[10001]{};
	dp[1] = grape[1];
	dp[2] = grape[1] + grape[2];
	for (int i = 3; i <= n; ++i)
		dp[i] = max(dp[i - 1], max(dp[i - 2], dp[i - 3] + grape[i - 1]) + grape[i]);

	cout << dp[n];
}
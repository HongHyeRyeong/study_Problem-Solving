#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int dp[11]{ 1, 1, 2, 4 };
	for (int i = 4; i < 11; ++i)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}
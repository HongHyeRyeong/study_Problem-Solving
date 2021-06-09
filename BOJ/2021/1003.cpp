#include <iostream>
using namespace std;

int main()
{
	int dp[41][2]{ {1, 0}, {0, 1} };
	for (int i = 2; i <= 40; ++i) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}

	int T, tmp;
	cin >> T;
	while (T--) {
		cin >> tmp;
		cout << dp[tmp][0] << " " << dp[tmp][1] << "\n";
	}
}
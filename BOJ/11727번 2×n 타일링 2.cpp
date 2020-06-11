#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int dp[1001]{ 0, 1, 3 };
	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	cout << dp[N] % 10007;
}
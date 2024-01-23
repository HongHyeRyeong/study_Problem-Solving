#include <vector>
using namespace std;

class Solution {
public:
	int dp[202][202];

	int minimumTotal(vector<vector<int>>& triangle) {
		int answer = 1e9;

		for (int i = 1; i <= triangle.size(); i++) {
			for (int j = 1; j <= i; j++) {
				dp[i][j] = triangle[i - 1][j - 1];

				if (j == 1) // 왼쪽 대각선
					dp[i][j] += dp[i - 1][j];
				else if (i == j) // 오른쪽 대각선
					dp[i][j] += dp[i - 1][j - 1];
				else
					dp[i][j] += min(dp[i - 1][j], dp[i - 1][j - 1]);
			}
		}

		for (int j = 1; j <= triangle.size(); j++)
			if (answer > dp[triangle.size()][j])
				answer = dp[triangle.size()][j];

		return answer;
	}
};
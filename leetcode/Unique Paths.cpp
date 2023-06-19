class Solution {
public:
    int dp[102][102]{};

    int uniquePaths(int m, int n) {
        dp[0][1] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[n][m];
    }
};
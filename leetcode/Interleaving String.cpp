#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;

        int m = s1.size(), n = s2.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        for (int i = m; i >= 0; --i) {
            for (int j = n; j >= 0; --j) {
                if (i == m && j == n)
                    dp[i][j] = true;
                else if (s1[i] == s3[i + j] && dp[i + 1][j])
                    dp[i][j] = true;
                else if (s2[j] == s3[i + j] && dp[i][j + 1])
                    dp[i][j] = true;
            }
        }

        return dp[0][0];
    }
};
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dp[502][502]{};

    int minDistance(string word1, string word2) {
        for (int i = 0; i < word1.size(); i++)
            dp[i + 1][0] = i + 1;
        for (int j = 0; j < word2.size(); j++)
            dp[0][j + 1] = j + 1;

        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1);
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
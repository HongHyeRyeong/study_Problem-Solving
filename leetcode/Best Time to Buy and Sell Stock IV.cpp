#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0)
            return 0;

        int dp[101][2]{};

        for (int j = 1; j <= k; ++j)
            dp[j][1] = -prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            for (int j = k; j > 0; --j) {
                dp[j][0] = max(dp[j][1] + prices[i], dp[j][0]); // 매도
                dp[j][1] = max(dp[j - 1][0] - prices[i], dp[j][1]); // 매수
            }
        }
        return dp[k][0];
    }
};

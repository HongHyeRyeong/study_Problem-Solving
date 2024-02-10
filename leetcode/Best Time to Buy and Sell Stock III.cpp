#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int> leftProfit(size, 0);
        vector<int> rightProfit(size, 0);

        int minPrice = prices[0];
        for (int i = 1; i < size; ++i) {
            minPrice = min(prices[i], minPrice);
            leftProfit[i] = max(leftProfit[i - 1], prices[i] - minPrice);
        }

        int maxPrice = prices[size - 1];
        for (int i = size - 2; i >= 0; --i) {
            maxPrice = max(prices[i], maxPrice);
            rightProfit[i] = max(rightProfit[i + 1], maxPrice - prices[i]);
        }

        int answer = 0;
        for (int i = 0; i < size; ++i)
            answer = max(answer, leftProfit[i] + rightProfit[i]);
        return answer;
    }
};
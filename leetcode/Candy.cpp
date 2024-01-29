#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candyCount(n, 1);

        // 정방향 계산
        for (int i = 1; i < n; ++i) {
            if (ratings[i - 1] < ratings[i]) {
                candyCount[i] = candyCount[i - 1] + 1;
            }
        }

        // 역방향 계산
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candyCount[i] = max(candyCount[i], candyCount[i + 1] + 1);
            }
        }

        int answer = 0;
        for (int i = 0; i < candyCount.size(); ++i)
            answer += candyCount[i];
        return answer;
    }
};
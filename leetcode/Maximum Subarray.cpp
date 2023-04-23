#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int answer = -10000, sum = 0;
        for (int a : nums) {
            sum += a;
            answer = max(answer, sum);
            if (sum < 0)
                sum = 0;
        }
        return answer;
    }
};
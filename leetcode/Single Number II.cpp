#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int first = 0, second = 0;

        for (int i = 0; i < nums.size(); ++i) {
            first ^= nums[i] & ~second;
            second ^= nums[i] & ~first;
        }

        return first;
    }
};
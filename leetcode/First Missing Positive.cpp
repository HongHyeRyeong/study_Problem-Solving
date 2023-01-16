#include <iostream>
#include <vector>
using namespace std;

#define MAX 100002

class Solution {
public:
    bool check[MAX]{};

    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            if (0 <= nums[i] && nums[i] < MAX)
                check[nums[i]] = true;

        for (int i = 1; i < MAX; ++i)
            if (check[i] == false)
                return i;
        return MAX - 1;
    }
};
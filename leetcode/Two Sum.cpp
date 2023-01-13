#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2);
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i)
            hash[nums[i]] = i;

        for (int i = 0; i < nums.size(); ++i)
            if (hash.find(target - nums[i]) != hash.end())
            {
                answer[0] = i;
                answer[1] = hash[target - nums[i]];

                if (answer[0] != answer[1])
                    break;
            }

        return answer;
    }
};
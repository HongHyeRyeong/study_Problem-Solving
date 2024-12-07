#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count = nums.size() / 3;
        unordered_map<int, int> hash;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];

            if (hash.find(num) == hash.end())
                hash[num]=0;
            
            if (hash[num] != -1)
            {
                hash[num]++;

                if (hash[num] > count)
                {
                    result.push_back(num);
                    hash[num] = -1;
                }
            }
        }

        return result;
    }
};

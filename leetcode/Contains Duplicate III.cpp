#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {        
        set<long> set;
        for (int i = 0; i < nums.size(); ++i) {
            auto lower = set.lower_bound(nums[i] - valueDiff);            
            if (lower != set.end() && *lower <= nums[i] + valueDiff)
                return true;
            
            set.insert(nums[i]);            
            if (i >= indexDiff)
                set.erase(nums[i - indexDiff]);
        }
        
        return false;
    }
};

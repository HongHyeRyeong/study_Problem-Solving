#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numCount[3]{};
        for (int i = 0; i < nums.size(); ++i)
            numCount[nums[i]]++;
        for (int i = 0, j = 0; j < 3; ++j) {
            while (numCount[j] > 0) {
                nums[i++] = j;
                numCount[j]--;
            }
        }
    }
};
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int answer = 0;
        int start = 0, end = nums.size() - 1, mid;

        while (start <= end) {
            mid = (start + end) / 2;

            if (nums[mid] == target) {
                answer = mid;
                break;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
                answer = mid + 1;
            }
            else {
                end = mid - 1;
                answer = mid;
            }
        }

        return answer;
    }
};
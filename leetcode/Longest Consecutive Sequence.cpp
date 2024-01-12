#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		set<int> s;
		for (int i = 0; i < nums.size(); ++i)
			s.insert(nums[i]);

		int prevValue = -1e6, length = 0, maxLength = 0;
		for (int value : s) {
			if (value == prevValue + 1) {
				++length;
				prevValue = value;
			}
			else {
				maxLength = max(maxLength, length);
				length = 1;
				prevValue = value;
			}
		}

		return max(maxLength, length);
	}
};
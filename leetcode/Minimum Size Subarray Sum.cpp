#include <vector>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int answer = 0;
		int start = 0, end = 0, sum = nums[0];

		while (true) {
			if (sum >= target) {
				int length = end - start + 1;
				if (answer == 0 || answer > length)
					answer = length;

				sum -= nums[start++];
				continue;
			}

			if (end == nums.size() - 1)
				break;

			sum += nums[++end];
		}

		return answer;
	}
};

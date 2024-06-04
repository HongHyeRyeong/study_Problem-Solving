#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string aStr = to_string(a), bStr = to_string(b);
            return (aStr + bStr) > (bStr + aStr);
            });

        string answer = "";
        for (int i : nums) {
            if (i == 0 && answer == "0")
                continue;
            answer += to_string(i);
        }

        return answer;
    }
};

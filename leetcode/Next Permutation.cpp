#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        // 참고로, 제공하는 알고리즘이 있다.
        //next_permutation(nums.begin(), nums.end());

        // 뒤에서부터 정렬이 깨지는 인덱스 찾기
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            --i;

        if (i == -1) {
            reverse(nums.begin(), nums.end());
        }
        else {
            // 정렬이 깨지는 인덱스 교환
            int j = i + 1;
            while (j < nums.size() && nums[i] < nums[j])
                j++;
            swap(nums[i], nums[j - 1]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        // �����, �����ϴ� �˰����� �ִ�.
        //next_permutation(nums.begin(), nums.end());

        // �ڿ������� ������ ������ �ε��� ã��
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            --i;

        if (i == -1) {
            reverse(nums.begin(), nums.end());
        }
        else {
            // ������ ������ �ε��� ��ȯ
            int j = i + 1;
            while (j < nums.size() && nums[i] < nums[j])
                j++;
            swap(nums[i], nums[j - 1]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};
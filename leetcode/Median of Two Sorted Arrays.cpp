#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums12(nums1.size() + nums2.size());
        copy(nums1.begin(), nums1.end(), nums12.begin());
        copy(nums2.begin(), nums2.end(), nums12.begin() + nums1.size());
        sort(nums12.begin(), nums12.end());

        double answer = 0;
        int size = nums12.size();
        if (size % 2 == 0)
            answer = (double)(nums12[size / 2 - 1] + nums12[size / 2]) / 2;
        else
            answer = nums12[size / 2];

        return answer;
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int answer = (end - start) * min(height[start], height[end]);
        while (start < end) {
            if (height[start] <= height[end])
                start++;
            else
                end--;

            answer = max(answer, (end - start) * min(height[start], height[end]));
        }

        return answer;
    }
};
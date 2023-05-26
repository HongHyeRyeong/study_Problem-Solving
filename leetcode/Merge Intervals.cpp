#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
            });

        vector<vector<int>> answer;
        answer.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            if (answer[answer.size() - 1][1] >= intervals[i][0])
                answer[answer.size() - 1][1] = max(intervals[i][1], answer[answer.size() - 1][1]);
            else
                answer.push_back(intervals[i]);
        }

        return answer;
    }
};
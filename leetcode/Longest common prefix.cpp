#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix = "";
        for (int i = 0; i < strs[0].size(); ++i) {
            string str = strs[0].substr(i, 1);

            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || str != strs[j].substr(i, 1)) {
                    str = "";
                    break;
                }
            }

            if (str == "")
                break;

            commonPrefix += str;
        }
        return commonPrefix;
    }
};
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> answer(numRows, "");
        int index = 0, upDown = 1;

        for (int i = 0; i < s.size(); ++i) {
            answer[index] += s[i];

            if (index == 0) upDown = 1;
            else if (index == numRows - 1) upDown = -1;

            index += upDown;
        }

        for (int i = 1; i < numRows; ++i)
            answer[0] += answer[i];
        return answer[0];
    }
};
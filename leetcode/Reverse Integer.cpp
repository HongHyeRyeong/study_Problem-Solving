#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        string str = to_string(abs(x));
        std::reverse(str.begin(), str.end());
        long reverseX = (x < 0 ? -1 : 1) * stol(str);

        int answer = 0;
        if (INT32_MIN <= reverseX && reverseX <= INT32_MAX)
            answer = reverseX;
        return answer;
    }
};
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string ss = "";
        for (int i = 0; i < s.size(); ++i)
            if (isalpha(s[i]) || isalnum(s[i]))
                ss += tolower(s[i]);

        int start = 0, end = ss.size() - 1;
        while (start <= end) {
            if (ss[start] != ss[end])
                break;
            start++, end--;
        }

        return start >= end;
    }
};
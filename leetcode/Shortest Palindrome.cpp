#include <string>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) 
    {
        int i = 0, n = s.size();
        for (int j = n - 1; j >= 0; --j)
            if (s[i] == s[j]) 
                ++i;

        if (i == n) 
            return s;

        string add = s.substr(i); // 추가해야 할 최소 문자열
        reverse(add.begin(), add.end());
        return add + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};

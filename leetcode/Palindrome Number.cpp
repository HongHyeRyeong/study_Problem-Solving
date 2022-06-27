#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s1, s2;
        s1 = s2 = to_string(x);
        std::reverse(s2.begin(), s2.end());
        return s1 == s2;
    }
};
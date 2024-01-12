#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> answer;
    vector<string> sub;

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return answer;
    }

    void dfs(string s, int index) {
        if (index == s.length()) {
            answer.push_back(sub);
            return;
        }

        for (int i = index; i < s.length(); i++) {
            string substr = s.substr(index, i - index + 1);
            if (!palindrome(substr))
                continue;
            sub.push_back(substr);
            dfs(s, i + 1);
            sub.pop_back();
        }
    }

    bool palindrome(string s) {
        int size = s.length();
        for (int i = 0; i < size / 2; i++)
            if (s[i] != s[size - i - 1])
                return false;
        return true;
    }
};
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        bool dp[1001]{ true };
        for (int i = 0; i <= s.length(); ++i) {
            for (string word : wordDict) {
                int index = i - word.length();
                if (0 <= index && word == s.substr(index, word.length()) && dp[index])
                    dp[i] = true;
            }
        }

        return dp[s.length()];
    }
};

#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int answer = 0;
        stack<int> st;
        vector<int> dp(s.size(), 0);

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(')
                st.push(i);
            else {
                if (st.empty())
                    continue;

                int index = st.top();
                st.pop();
                dp[i] = i - index + 1 + (index > 0 ? dp[index - 1] : 0);
            }
            answer = max(answer, dp[i]);
        }

        return answer;
    }
};
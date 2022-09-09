#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool valid = true;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else if (c == ')' && !st.empty() && st.top() == '(')
                st.pop();
            else if (c == '}' && !st.empty() && st.top() == '{')
                st.pop();
            else if (c == ']' && !st.empty() && st.top() == '[')
                st.pop();
            else {
                valid = false;
                break;
            }
        }

        return valid && st.empty();
    }
};
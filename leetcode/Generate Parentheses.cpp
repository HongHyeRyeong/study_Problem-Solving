#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> answer;

    vector<string> generateParenthesis(int n) {
        f("", 0, 0, n);
        return answer;
    }

    void f(string s, int left, int right, int n) {
        if (s.length() == n * 2) {
            answer.push_back(s);
            return;
        }

        if (left < n)
            f(s + "(", left + 1, right, n);
        if (left > right)
            f(s + ")", left, right + 1, n);
    }
};
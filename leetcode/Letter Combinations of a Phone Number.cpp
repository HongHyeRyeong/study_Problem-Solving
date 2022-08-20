#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> answer;
    string digitsToLetters[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    void makeLetters(string digits, string letters, int digitIndex) {
        if (digits.size() == digitIndex) {
            answer.push_back(letters);
            return;
        }

        int num = digits[digitIndex] - '0';
        for (int i = 0; i < digitsToLetters[num].size(); ++i)
            makeLetters(digits, letters + digitsToLetters[num][i], digitIndex + 1);
    }

    vector<string> letterCombinations(string digits) {
        if (digits != "") {
            makeLetters(digits, "", 0);
            sort(answer.begin(), answer.end());
        }

        return answer;
    }
};
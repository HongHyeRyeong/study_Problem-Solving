#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int answer = 0, length = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (length != 0)
                    answer = length;
                length = 0;
            }
            else {
                length++;
            }
        }

        if (length != 0)
            answer = length;

        return answer;
    }
};
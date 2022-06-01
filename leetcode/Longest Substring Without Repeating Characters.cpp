#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int answer = 0;

        for (int startIndex = 0, endIndex = 0; endIndex < s.size(); ++endIndex) {
            char c = s[endIndex];

            if (hash[c] != 0)
                startIndex = max(startIndex, hash[c]);

            answer = max(answer, endIndex - startIndex + 1);
            hash[c] = endIndex + 1;
        }

        return answer;
    }
};
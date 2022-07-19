#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<string, int> m;
        m["I"] = 1, m["V"] = 5, m["X"] = 10, m["L"] = 50, m["C"] = 100, m["D"] = 500, m["M"] = 1000;
        m["IV"] = 4, m["IX"] = 9, m["XL"] = 40, m["XC"] = 90, m["CD"] = 400, m["CM"] = 900;

        long answer = 0;
        for (int i = 0; i < s.size(); ++i) {
            // 2글자 검사
            auto iter = m.find(s.substr(i, 2));
            if (iter != m.end()) {
                answer += iter->second;
                ++i;
                continue;
            }

            // 1글자 검사
            iter = m.find(s.substr(i, 1));
            if (iter != m.end()) {
                answer += iter->second;
            }
        }

        return answer;
    }
};
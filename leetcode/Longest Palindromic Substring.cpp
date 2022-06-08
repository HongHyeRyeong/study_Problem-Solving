#include <string>
using namespace std;

class Solution {
public:
	bool dp[1001][1001]{};

	string longestPalindrome(string s) {
		// 1글자
		string answer = s.substr(0, 1);
		for (int i = 0; i < s.size(); i++)
			dp[i][i] = true;

		// 2글자
		for (int i = 0; i < s.size() - 1; i++)
			if (s[i] == s[i + 1]) {
				dp[i][i + 1] = true;
				answer = s.substr(i, 2);
			}

		// 3글자 이상
		for (int i = 3; i <= s.size(); i++)
			for (int j = 0; j + i <= s.size(); j++)
				if (dp[j + 1][j + i - 2] && s[j] == s[j + i - 1]) {
					dp[j][j + i - 1] = true;
					if (answer.size() < i)
						answer = s.substr(j, i);
				}

		return answer;
	}
};
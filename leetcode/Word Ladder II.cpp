#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> answers;
    vector<string> answer;
    bool check[500];
    map<string, int> counts;
    int minCount;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        minCount = 0;
        queue<pair<string, int>> q;
        q.push({ beginWord, 0 });
        while (!q.empty()) {
            string word = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if (word == endWord) {
                minCount = cnt;
                break;
            }

            for (int i = 0; i < wordList.size(); i++)
            {
                if (check[i] || isNearWord(word, wordList[i]) == false)
                    continue;
                check[i] = true;
                q.push({ wordList[i], cnt + 1 });
            }
        }

        memset(check, false, sizeof(check));
        answer.push_back(beginWord);
        dfs(beginWord, endWord, wordList, 0);
        return answers;
    }

    bool dfs(string& curWord, string& endWord, vector<string>& wordList, int count) {
        if (count == minCount) {
            if (curWord != endWord)
                return false;
            else {
                answers.push_back(answer);
                return true;
            }
        }
        else if (counts.find(curWord) != counts.end() && counts[curWord] <= count)
            return false;

        bool movable = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (check[i] || isNearWord(curWord, wordList[i]) == false)
                continue;

            check[i] = true;
            answer.push_back(wordList[i]);
            if (dfs(wordList[i], endWord, wordList, count + 1))
                movable = true;
            answer.pop_back();
            check[i] = false;
        }

        if (movable == false)
            counts[curWord] = count;
        return movable;
    }

    bool isNearWord(string& cur, string& next) {
        int cnt = 0;
        for (int i = 0; i < cur.size(); i++)
            if (cur[i] != next[i])
                cnt++;
        return cnt == 1;
    }
};
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pathSplit;
        string split = "";
        for (int i = 0; i <= path.size(); ++i) {
            if (i == path.size() || path[i] == '/') {
                if (split != "") {
                    if (split == ".") {
                        split = "";
                        continue;
                    }
                    else if (split == "..") {
                        if (!pathSplit.empty())
                            pathSplit.pop();
                    }
                    else
                        pathSplit.push(split);
                }
                split = "";
            }
            else
                split += path[i];
        }

        string answer = "";
        while (!pathSplit.empty()) {
            answer = "/" + pathSplit.top() + answer;
            pathSplit.pop();
        }
        return answer == "" ? "/" : answer;
    }
};
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<int>> hash;

    vector<int> diffWaysToCompute(string expression) {
        if (hash.find(expression) != hash.end())
            return hash[expression];

        vector<int> result;

        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];

            if (c == '+' || c == '-' || c == '*') {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> leftResults = diffWaysToCompute(left);
                vector<int> rightResults = diffWaysToCompute(right);

                for (int l : leftResults) {
                    for (int r : rightResults) {
                        if (c == '+') {
                            result.push_back(l + r);
                        }
                        else if (c == '-') {
                            result.push_back(l - r);
                        }
                        else if (c == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }

        if (result.empty())
            result.push_back(stoi(expression));

        hash[expression] = result;
        return result;
    }
};

#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;

        for (int i = 0; i < strs.size(); ++i) {
            string sortStr = strs[i];
            sort(sortStr.begin(), sortStr.end());

            if (hash.find(sortStr) == hash.end()) {
                vector<string> v;
                v.push_back(strs[i]);
                hash.insert(make_pair(sortStr, v));
            }
            else {
                hash[sortStr].push_back(strs[i]);
            }
        }

        vector<vector<string>> answer;
        for (auto iter = hash.begin(); iter != hash.end(); ++iter) {
            answer.push_back(iter->second);
        }

        return answer;
    }
};
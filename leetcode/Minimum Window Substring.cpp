#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        vector<char> hash_kind;
        for (int i = 0; i < t.length(); ++i) {
            if (hash[t[i]] == 0)
                hash_kind.push_back(t[i]);
            hash[t[i]]++;
        }

        int length = t.length();
        while (length <= s.length()) {
            int start = 0, end = length - 1;
            for (int i = start; i <= end; ++i)
                hash[s[i]]--;

            for (int i = 0; i < hash_kind.size(); ++i) {
                if (hash[hash_kind[i]] > 0)
                    break;
                if (i == hash_kind.size() - 1)
                    return s.substr(start, length);
            }

            while (end < s.length() - 1) {
                hash[s[start++]]++;
                hash[s[++end]]--;

                for (int i = 0; i < hash_kind.size(); ++i) {
                    if (hash[hash_kind[i]] > 0)
                        break;
                    if (i == hash_kind.size() - 1)
                        return s.substr(start, length);
                }
            }

            length++;
            for (int i = start; i <= end; ++i)
                hash[s[i]]++;
        }

        return "";
    }
};
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string ss, pp;
    int sSize, pSize;

    bool isMatch(string s, string p) {
        ss = s, pp = p;
        sSize = ss.size(), pSize = pp.size();
        return match(0, 0);
    }

    bool match(int i, int j)
    {
        if (j == pSize)
            return i == sSize;

        if (j + 1 < pSize && pp[j + 1] == '*')
        {
            if (match(i, j + 2))
                return true;
            while (i < sSize && (pp[j] == ss[i] || pp[j] == '.'))
            {
                if (match(++i, j + 2))
                    return true;
            }
        }
        else if (i < sSize && (pp[j] == '.' || ss[i] == pp[j]) && match(i + 1, j + 1))
            return true;

        return false;
    }
};
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        int answer = 0;
        int c = matrix[0].size();
        vector<int> h(c + 1, 0);

        for (auto &v : matrix)
        {
            for (int i = 0; i < c; ++i)
                h[i] = v[i] == '0' ? 0 : h[i] + 1;

            stack<int> s;
            for (int i = 0; i <= c;)
            {
                if (s.empty() || h[i] >= h[s.top()])
                    s.push(i++);
                else
                {
                    int cur = s.top();
                    s.pop();
                    answer = max(answer, h[cur] * (s.empty() ? i : (i - s.top() - 1)));
                }
            }
        }

        return answer;
    }
};

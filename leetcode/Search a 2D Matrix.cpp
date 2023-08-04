#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        vector<int> list;
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                list.push_back(matrix[i][j]);

        int start = 0, end = list.size() - 1, mid;
        while (start <= end)
        {
            mid = (start + end) / 2;

            if (list[mid] == target)
                return true;
            else if (list[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return false;
    }
};
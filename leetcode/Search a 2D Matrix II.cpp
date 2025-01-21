#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = 0;
        int col = matrix[0].size() - 1;

        while (row < matrix.size() && col < matrix[0].size())
        {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                col--;
            else
                row++;
        }

        return false;
    }
};

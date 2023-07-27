#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> column, row;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    column.insert(i);
                    row.insert(j);
                }
            }
        }

        for (int i = 0; i < matrix.size(); ++i) {
            if (column.find(i) != column.end()) {
                for (int j = 0; j < matrix[0].size(); ++j)
                    matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < matrix[0].size(); ++i) {
            if (row.find(i) != row.end()) {
                for (int j = 0; j < matrix.size(); ++j)
                    matrix[j][i] = 0;
            }
        }
    }
};
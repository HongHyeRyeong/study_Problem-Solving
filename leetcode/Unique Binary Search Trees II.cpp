#include <vector>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> dfs(int start, int end) {
        vector<TreeNode*> answer;

        if (start > end) {
            answer.push_back(nullptr);
            return answer;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = dfs(start, i - 1);
            vector<TreeNode*> right = dfs(i + 1, end);

            for (int j = 0; j < left.size(); j++)
                for (int k = 0; k < right.size(); k++)
                    answer.push_back(new TreeNode(i, left[j], right[k]));
        }

        return answer;
    }

    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
};
#include <vector>
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
    vector<vector<int>> answer;

    void f(int index, TreeNode* root)
    {
        if (root == nullptr)
            return;

        if (answer.size() <= index) {
            vector<int> v;
            answer.push_back(v);
        }

        answer[index].push_back(root->val);
        f(index + 1, root->left);
        f(index + 1, root->right);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        f(0, root);
        return answer;
    }
};
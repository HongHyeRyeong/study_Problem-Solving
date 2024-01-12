
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
    TreeNode* node1;
    TreeNode* node2;
    TreeNode* prev;

    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;

        dfs(root->left);

        if (prev && root->val < prev->val) {
            node2 = root;
            if (node1 == nullptr)
                node1 = prev;
            else 
                return;
        }

        prev = root;
        dfs(root->right);
    }

    void recoverTree(TreeNode* root) {
        dfs(root);

        int tmp = node1->val;
        node1->val = node2->val;
        node2->val = tmp;
    }
};
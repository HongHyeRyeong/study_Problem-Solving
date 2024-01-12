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
    int answer = 0;
    
    int sumNumbers(TreeNode* root) {
        Sum(root, 0);
        return answer;
    }
    
    void Sum(TreeNode* root, int num) {
        if (root == nullptr)
            return;

        int n = num * 10 + root->val;
        if (root->left == nullptr) {
            if (root->right == nullptr)
                answer += n;
            Sum(root->right, n);
        }
        else {
            Sum(root->right, n);
            Sum(root->left, n);
        }
    }
};
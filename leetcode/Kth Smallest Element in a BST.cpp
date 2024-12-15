#include <stack>
using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while (root != nullptr || s.empty() == false) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();

            k--;
            if (k == 0)
                return root->val;
            
            root = root->right;
        }

        return -1;
    }
};

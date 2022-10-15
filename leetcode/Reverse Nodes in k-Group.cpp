class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *root = head;
        vector<ListNode*> v(k);

        while (true)
        {
            for (int i = 0; i < k; ++i)
            {
                if (root == nullptr)
                    return head;
                v[i] = root;
                root = root->next;
            }

            for (int i = 0; i < k / 2; i++)
                SwapVal(v[i], v[k - i - 1]);
        }
    }

    void SwapVal(ListNode *node1, ListNode *node2)
    {
        int val = node1->val;
        node1->val = node2->val;
        node2->val = val;
    }
};
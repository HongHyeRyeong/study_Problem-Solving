struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *node = head;
        ListNode *preNode = node;
        int preVal = -1;
        while (node != nullptr)
        {
            if (preVal == -1)
            {
                preNode = node;
                preVal = node->val;
            }
            else
            {
                preNode->val = node->val;
                node->val = preVal;
                preVal = -1;
            }
            node = node->next;
        }
        return head;
    }
};
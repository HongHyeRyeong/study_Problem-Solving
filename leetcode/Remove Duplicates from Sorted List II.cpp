
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // head가 중복값
        bool isHeadDuplicate = false;
        if (head != nullptr && head->next != nullptr && head->val == head->next->val)
            isHeadDuplicate = true;

        // 중간이 중복값
        ListNode* node = head;
        ListNode* pre = head;
        while (node != nullptr) {
            if (node->next != nullptr && node->val == node->next->val) {
                int val = node->val;
                while (node != nullptr && node->val == val) {
                    pre->next = node->next;
                    node = node->next;
                }

                node = pre;
            }

            pre = node;
            node = node->next;
        }

        if (isHeadDuplicate)
            head = head->next;

        return head;
    }
};
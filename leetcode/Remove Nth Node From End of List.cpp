class Solution {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr)
            return nullptr;

        ListNode* temp = head;
        int size = 0;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }

        ListNode* node = head;
        ListNode* pre = head;
        for (int i = 0; i < size; ++i) {
            if (i == size - n) {
                if (node == head) // ½ÃÀÛ
                    head = head->next;
                else if (node->next == nullptr) // ³¡
                    pre->next = nullptr;
                else
                    pre->next = node->next;

                delete(node);
                break;
            }

            pre = node;
            node = node->next;
        }

        return head;
    }
};
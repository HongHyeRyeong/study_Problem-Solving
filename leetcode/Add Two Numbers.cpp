#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode();
        ListNode* node = root;
        int num = 0;

        while (true) {
            if (l1) {
                num += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                num += l2->val;
                l2 = l2->next;
            }

            node->val = num % 10;
            num /= 10;

            if (l1 || l2 || num) {
                node->next = new ListNode();
                node = node->next;
            }
            else
                break;
        }

        return root;
    }
};
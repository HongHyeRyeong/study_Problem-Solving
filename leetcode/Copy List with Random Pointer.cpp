#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        unordered_map<Node*, Node*> nodeList;

        Node* node = head;
        while (node != NULL) {
            Node* newNode = new Node(node->val);
            nodeList[node] = newNode;
            node = node->next;
        }

        node = head;
        while (node != NULL) {
            if (node->next != NULL)
                nodeList[node]->next = nodeList[node->next];
            if (node->random != NULL)
                nodeList[node]->random = nodeList[node->random];
            node = node->next;
        }

        return nodeList[head];
    }
};
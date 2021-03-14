#include <iostream>

struct Node {
    int val;
    Node *next;

    Node (int val)
        : val(val), next(nullptr)
    {}
};

void print_list(Node *n);

void sum_list_rev(Node *n1, Node *n2) {
    bool carry_over = false;

    Node head(-1);
    Node *prev = new Node(-1);
    head.next = prev;

    while (n1 != nullptr || n2 != nullptr) {
        int val;
        if (n1 != nullptr && n2 != nullptr) {
            val = carry_over ? n1->val + n2->val + 1
                             : n1->val + n2->val;
        } else if (n1 == nullptr) {
            val = carry_over ? n2->val + 1
                             : n2->val;
        } else {
            val = carry_over ? n1->val + 1
                             : n1->val;
        }
        carry_over = (val >= 10) ? true : false;

        Node *cur = new Node(val % 10);
        prev->next = cur;
        prev = cur;

        n1 = (n1 != nullptr) ? n1->next : nullptr;
        n2 = (n2 != nullptr) ? n2->next : nullptr;
    }

    if (carry_over)
        prev->next = new Node(1);

    print_list(head.next->next);
}

void sum_list_forward(Node *n1, Node *n2) {
}

void print_list(Node *n) {
    while (n != nullptr) {
        std::cout << n->val << "->";
        n = n->next;
    }
    std::cout << std::endl;
}

int main() {
    Node *n1_1 = new Node(9);
    Node *n1_2 = new Node(9);
    Node *n1_3 = new Node(9);

    Node *n2_1 = new Node(9);
    Node *n2_2 = new Node(9);
    Node *n2_3 = new Node(9);

    n1_1->next = n1_2;
    n1_2->next = n1_3;
    n2_1->next = n2_2;
    n2_2->next = n2_3;

    sum_list_rev(n1_1, n2_1);
}

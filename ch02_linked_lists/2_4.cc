#include <iostream>

struct Node {
    int val;
    Node *next;
    bool has_partition;

    Node(int val):
        val(val), next(nullptr)
    {}
};

void partition(Node *n, int pivot) {
    Node *head_l = new Node(-1);
    Node *head_r = new Node(-1);

    Node *cur_l = head_l;
    Node *cur_r = head_r;

    Node *runner = n;
    while (runner != nullptr) {
        if (runner->val < pivot) {
            cur_l->next = runner;
            cur_l = cur_l->next;
        } else {
            cur_r->next = runner;
            cur_r = cur_r->next;
        }

        runner = runner->next;
    }

    cur_l->has_partition = true;
    cur_l->next = head_r->next;
    cur_r->next = nullptr;
    *n = *(head_l->next);
}

void print_list(Node *n) {
    while (n != nullptr) {
        if (n->has_partition)
            std::cout << n->val << " | ";
        else
            std::cout << n->val << "->";
        n = n->next;
    }
    std::cout << std::endl;
}

int main() {
    Node *n1 = new Node(3);
    Node *n2 = new Node(5);
    Node *n3 = new Node(8);
    Node *n4 = new Node(5);
    Node *n5 = new Node(10);
    Node *n6 = new Node(2);
    Node *n7 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;

    partition(n1, 5);
    print_list(n1);
}

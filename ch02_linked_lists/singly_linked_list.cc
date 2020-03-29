#include <iostream>

struct Node {
    int val;
    Node *next;
};

Node *newNode(int val) {
   Node *n = new Node;
   n->val = val;
   return n;
}

// singly linked list
struct SLL {
    Node *head;
    Node *tail;
    int len;

    SLL() {
        this->len = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    void add(int val) {
        Node *n = newNode(val);
        if (this->len == 0) {
            this->head = n;
            this->tail = n;
            n->next = n;
        } else if (this->len == 1) {
            this->tail = n;
            this->head->next = this->tail;
            this->tail->next = this->head;
        } else {
            this->tail->next = n;
            this->tail = n;
            this->tail->next = this->head;
        }
        this->len++;
    }

    void printSLL() {
        Node *n = this->head;
        for (int i = 0; i < this->len; i++) {
            if (i == 0) {
                std::cout << "[" << n->val << "] -> ";
            } else if (i == this->len - 1) {
                std::cout << "(" << n->val << ")" << std::endl;;
            } else {
                std::cout << n->val << " -> ";
            }
            n = n->next;
        }
    }
};

int main() {
    SLL sll = SLL();

    sll.add(0);
    sll.add(2);
    sll.add(4);
    sll.add(6);
    sll.add(8);

    sll.add(1);
    sll.add(3);
    sll.add(5);
    sll.add(7);
    sll.add(9);

    sll.printSLL();
}

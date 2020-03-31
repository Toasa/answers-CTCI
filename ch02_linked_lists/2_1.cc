// 1. using map<int, int>, remove duplicate
// 2. using double pointer (runner technique)

#include <iostream>
#include <map>

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

void sllFrom(SLL &sll, int *arr, int len) {
   for (int i = 0; i < len; i++) {
       sll.add(arr[i]);
   }
}

void removeDuplicateUsingMap(SLL &sll) {
    std::map<int, int> dup_count;

    // sll.len == 2の場合
    if (sll.len == 2) {
        if (sll.head->val == sll.tail->val) {
            sll.len--;
            sll.tail = sll.head;
            sll.head->next = sll.head;
        }
        return;
    }

    // SLL is circularly so `follow` follows one behind `n`.
    Node *n = sll.head->next;
    Node *follow = sll.head;
    dup_count[sll.head->val]++;

    for (; follow != sll.tail; n = n->next) {
        dup_count[n->val]++;

        // has duplication
        if (dup_count[n->val] > 1) {

            while (dup_count[n->val] > 1 && n != sll.tail) {
                n = n->next;
                dup_count[n->val]++;
                sll.len--;
            }

            if (n == sll.tail && dup_count[n->val] > 1) {
                sll.tail = follow;
                sll.len--;
                return;
            }
            follow->next = n;
        }
        follow = n;
    }
}

// WANT: testing API
void equal(SLL sll, int *expected, int expected_len) {
    Node *n = sll.head;
    for (int i = 0; i < sll.len; i++, n = n->next) {
        if (n->val != expected[i]) {
            std::cout << "testing FAILED" << std::endl;
            SLL sll_expected = SLL();
            sllFrom(sll_expected, expected, expected_len);
            printf("expected: ");
            sll_expected.printSLL();
            printf("but got : ");
            sll.printSLL();
            printf("\n");
            return;
        }
    }
    std::cout << "testing OK" << std::endl;
}

int main() {
    SLL sll0 = SLL();
    int arr0[6] = {
        0, 2, 0, 3, 4, 6
    };
    sllFrom(sll0, arr0, 6);
    removeDuplicateUsingMap(sll0);
    int expected0[5] = {
        0, 2, 3, 4, 6
    };
    equal(sll0, expected0, 5);

    SLL sll1 = SLL();
    int arr1[6] = {
        0, 2, 2, 2, 4, 6
    };
    sllFrom(sll1, arr1, 6);
    removeDuplicateUsingMap(sll1);
    int expected1[4] = {
        0, 2, 4, 6
    };
    equal(sll1, expected1, 4);

    SLL sll2 = SLL();
    int arr2[6] = {
        0, 1, 2, 3, 3, 3
    };
    sllFrom(sll2, arr2, 6);
    removeDuplicateUsingMap(sll2);
    int expected2[4] = {
        0, 1, 2, 3
    };
    equal(sll2, expected2, 4);

    SLL sll3 = SLL();
    int arr3[8] = {
        0, 1, 2, 3, 3, 3, 2, 5
    };
    sllFrom(sll3, arr3, 8);
    removeDuplicateUsingMap(sll3);
    int expected3[5] = {
        0, 1, 2, 3, 5
    };
    equal(sll3, expected3, 5);
}

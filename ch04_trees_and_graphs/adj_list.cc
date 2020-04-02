#include<iostream>
#include<vector>

struct Node {
    int val;
    std::vector<Node *> adjs;

    Node(int val) {
        this->val = val;
    }
};

int main() {
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);

    n1->adjs.push_back(n2);
    n1->adjs.push_back(n3);
    n1->adjs.push_back(n8);
    n2->adjs.push_back(n3);
    n3->adjs.push_back(n5);
    n3->adjs.push_back(n6);
    n5->adjs.push_back(n6);
    n7->adjs.push_back(n6);
    n7->adjs.push_back(n8);
    n8->adjs.push_back(n4);

    Node *nodes[8] = {
        n1, n2, n3, n4,
        n5, n6, n7, n8
    };

    return 0;
}

#include <iostream>

struct Node {
    Node *lhs;
    Node *rhs;

    Node()
        : lhs(nullptr),
          rhs(nullptr)
    {}
};

Node *copy(Node *n) {
    if (n == nullptr) {
        return nullptr;
    }

    Node *ret = new(Node);
    if (n->lhs != nullptr) {
        ret->lhs = copy(n->lhs);
    }
    if (n->rhs != nullptr) {
        ret->rhs = copy(n->rhs);
    }
    return ret;
}

int node_count(Node *n) {
    if (n == nullptr) {
        return 0;
    }

    int count = 1;
    if (n->lhs != nullptr) {
        count += node_count(n->lhs);
    }
    if (n->rhs != nullptr) {
        count += node_count(n->rhs);
    }
    return count;
}

int main() {
    Node *root = new(Node);

    Node *l = new(Node);
    Node *r = new(Node);
    root->lhs = l;
    root->rhs = r;

    Node *ll = new(Node);
    Node *lr = new(Node);
    l->lhs = ll;
    l->rhs = lr;

    Node *copied = copy(root);
    
    std::cout << "node count: " << node_count(root) << std::endl;
    std::cout << "node count: " << node_count(copied) << std::endl;
}


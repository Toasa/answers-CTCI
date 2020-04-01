#include <iostream>

// Noduplication binary search tree.
struct Node {
    int val;
    Node *lhs;
    Node *rhs;

    Node(int val) {
        this->val = val;
        this->lhs = nullptr;
        this->rhs = nullptr;
    }
};

Node *buildBinarySearchTree(int *arr, int len) {
    Node *root = new Node(arr[0]);
    Node *node_iter;

    for (int i = 1; i < len; i++) {
        node_iter = root;
        int val = arr[i];
        Node* new_node = new Node(val);

        while(true) {
            int iter_val = node_iter->val;

            if (node_iter->lhs == nullptr && val < iter_val) {
                node_iter->lhs = new_node;
                break;
            } else if (node_iter->rhs == nullptr && val > iter_val) {
                node_iter->rhs = new_node;
                break;
            } else if (node_iter->lhs != nullptr && val < iter_val) {
                node_iter = node_iter->lhs;
            } else if (node_iter->rhs != nullptr && val > iter_val) {
                node_iter = node_iter->rhs;
            } else {
                // I assume No duplication of src array, so this pass doesn't reached
                std::cerr << "INVALID PATH" << std::endl;
                exit(1);
            }
        }
    }

    return root;
}

void outputDotFormatEachNode(Node *n) {
    if (n->lhs != nullptr) {
        std::cout << "  " << n->val << " -> " << n->lhs->val << std::endl;
        outputDotFormatEachNode(n->lhs);
    }
    if (n->rhs != nullptr) {
        std::cout << "  " << n->val << " -> " << n->rhs->val << std::endl;
        outputDotFormatEachNode(n->rhs);
    }
}

void outputDotFormat(Node *root) {
    std::cout << "digraph G {" << std::endl;
    outputDotFormatEachNode(root);
    std::cout << "}" << std::endl;
}

int main() {
    int arr[10] = {30, 12, 2, 15, 42, 8, 23, 1, 77, 0};
    Node *root = buildBinarySearchTree(arr, 10);
    outputDotFormat(root);
    return 0;
}

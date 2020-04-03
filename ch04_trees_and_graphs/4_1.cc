#include<iostream>
#include<queue>
#include<vector>

struct Node {
    int val;
    std::vector<Node *> adjs;

    Node(int val) {
        this->val = val;
    }
};

bool pathExists(std::vector<Node *> nodes, int src_num, int dst_num) {
    Node *src = nodes[src_num - 1];
    Node *dst = nodes[dst_num - 1];

    std::vector<bool> visited(nodes.size() + 1);
    for (int i = 0; i <= nodes.size() + 1; i++) {
        visited[i] = false;
    }

    std::queue<Node *> q;
    q.push(src);
    visited[src_num] = true;

    while (!q.empty()) {
        Node *n = q.front();
        q.pop();

        if (n->val == dst_num) { return true; }

        for (auto adj : n->adjs) {
            if (!visited[adj->val]) {
                q.push(adj);
                visited[adj->val] = true;
            }
        }
    }
    return false;
}

int main() {
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(8);
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

    std::vector <Node *> nodes = {
        n1, n2, n3, n4,
        n5, n6, n7, n8
    };

    // path exists node1 -> node4 ?
    if (pathExists(nodes, 1, 4)) {
        std::cout << "EXISTS" << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    return 0;
}

#include <iostream>
#include <string>

struct Node {
    std::string key;
    int val;
    Node *next;
};

Node *newNode(std::string key, int val);

struct HashMap {
    const static int arr_size = 10;
    Node *arr[arr_size];

    int hash(std::string s) {
       return s.size() % arr_size;
    }

    void add(std::string key, int val) {
       int hash_val = hash(key);
       Node *n = newNode(key, val);
       if (arr[hash_val] == nullptr) {
           this->arr[hash_val] = n;
       } else {
           Node *iter = arr[hash_val];
           while (iter->next != nullptr) {
               iter = iter->next;
           }
           iter->next = n;
       }
    }

    int get(std::string key) {
        int hash_val = hash(key);
        Node *iter = arr[hash_val];
        while (iter != nullptr) {
            if (iter->key == key) {
                return iter->val;
            }
            iter = iter->next;
        }

        // Not found
        return -1;
    }

};

HashMap newHashMap() {
    HashMap hm;
    for (int i = 0; i < hm.arr_size; i++) {
        hm.arr[i] = nullptr;
    }
    return hm;
}

Node *newNode(std::string key, int val) {
    Node *n = new Node;
    n->key = key;
    n->val = val;
    n->next = nullptr;
    return n;
}

int main() {
    HashMap hm = newHashMap();

    std::string s1 = "atsushi";
    std::string s2 = "takashi";
    std::string s3 = "jun";
    std::string s4 = "akiko";

    hm.add(s1, 28);
    hm.add(s2, 26);
    hm.add(s3, 18);
    hm.add(s4, 70);

    std::cout << hm.get("atsushi") << std::endl;
    std::cout << hm.get("takashi") << std::endl;
    std::cout << hm.get("akiko") << std::endl;
    std::cout << hm.get("jun") << std::endl;
}

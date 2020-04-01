#include <iostream>

struct Node {
    int val;
    // 自分と自分より下に積まれたノードの中での
    // 最小値を記録する
    int min_memo;
};

struct MinStack {
    const static int SIZE = 100;
    Node inner_arr[SIZE];
    int len;

    MinStack() {
       this->len = 0;
    }

    void push(int val) {
        Node n;
        n.val = val;
        if (this->len == 0) {
            n.min_memo = val;
        } else {
            int old_min = this->inner_arr[this->len-1].min_memo;
            n.min_memo = (old_min < val) ? old_min : val;
        }
        this->inner_arr[this->len] = n;
        this->len++;
    }

    int pop() {
        this->len--;
        return (this->inner_arr[this->len]).val;
    }

    int getMin() {
        return (this->inner_arr[this->len-1]).min_memo;
    }
};

int main() {
    MinStack s = MinStack();
 
    s.push(20);
    s.push(4);
    s.push(3);
    s.push(1);
    s.push(10);
    s.push(3);

    std::cout << s.getMin() << std::endl;
    s.pop();
    std::cout << s.getMin() << std::endl;
    s.pop();
    std::cout << s.getMin() << std::endl;
    s.pop();
    std::cout << s.getMin() << std::endl;

    return 0;
}

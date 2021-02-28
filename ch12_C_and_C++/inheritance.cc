#include <iostream>

struct Base {
    virtual void f1() {
        std::cout << "f1 in Base" << std::endl;
    }
    virtual void f2() {
        std::cout << "f2 in Base" << std::endl;
    }
};

struct D1 : Base {
    void f1() {
        std::cout << "f1 in D1" << std::endl;
    }
};

int main() {
    Base *b1 = new Base();
    Base *d1 = new D1();

    b1->f1();
    d1->f1();
}


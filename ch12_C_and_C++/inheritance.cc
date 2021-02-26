#include <iostream>

class Animal {
    int id;

    public:
    void aboutMe() {
        std::cout << "I'm animal" << std::endl;
    }
};

class Cat : public Animal {
    public:
    void aboutMe() {
        std::cout << "I'm cat" << std::endl;
    }
};

int main() {
    Animal *a = new Animal();
    a->aboutMe();
    Cat *c = new Cat();
    c->aboutMe();
}


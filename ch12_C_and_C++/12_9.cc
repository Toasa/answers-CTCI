#include <iostream>

// // smart pointer を実現する１方法
// template <typename T>
// struct smart_ptr {
//     T *ptr;
//     smart_ptr()
//         : ptr(new T)
//     {}
// 
//     ~smart_ptr()
//     { delete ptr; }
// 
//     T & operator *() const {
//         return *ptr;
//     }
// };

template <typename T>
class Obj {
public:
    T *getPtr(); // ++ref_count
    void release(); // --ref_count

private:
    T val;
    int ref_count;
}

int main() {
    smart_ptr<int> ptr;
    *ptr = 123;
    std::cout << *ptr << std::endl;
    return 0;
}


#include <iostream>

int setBit(int n, int bit) {
    return n | (1 << bit);
}

int clearBit(int n, int bit) {
    int mask = ~(1 << bit);
    return n & mask;
}

int insert(int N, int M, int start_i, int end_i) {
    for (int i = start_i; i <= end_i; i++) {
        N = clearBit(N, i);
    }

    M <<= start_i;
    return N | M;
}


int main() {
    int N = 0b10000000000;
    int M = 0b10011;
    int i = 2;
    int j = 6;

    int result = insert(N, M, i, j);
    std::cout << std::bitset<11>(insert(N, M, i, j)) << std::endl;
}

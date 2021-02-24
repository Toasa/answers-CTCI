#include <stdio.h>
#include <stdlib.h>

struct BitVec {
    char *vec;
};

struct BitVec *new(int size) {
    struct BitVec *bv = calloc(1, sizeof(struct BitVec));
    bv->vec = calloc(1, (size+7)/8);
    return bv;
}

void set(struct BitVec *bv, int n) {
    bv->vec[n / 8] |= 1 << (n % 8);
}

int get(struct BitVec *bv, int n) {
    return (bv->vec[n / 8] & (1 << (n % 8))) != 0;
}

int main() {
    // const int N = 32000;
    const int N = 32;
    int arr[N] = {
        1, 14, 23, 11, 16, 2, 8, 8,
        19, 2, 3, 4, 6, 5, 9, 10,
        20, 21, 22, 23, 24, 25, 26, 27,
        30, 9, 31, 27, 19, 29, 28, 7
    };

    struct BitVec *bv = new(N);
    for (int i = 0; i < N; i++) {
        int n = arr[i];
        if (get(bv, n)) {
            printf("dup: %d\n", n);
        } else {
            set(bv, n);
        }
    }
}

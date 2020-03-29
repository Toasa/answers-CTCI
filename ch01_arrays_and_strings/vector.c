#include <stdio.h>
#include <stdlib.h>

struct Vector {
    int *v;
    int len;
    int max;
};

struct Vector genVector() {
    struct Vector v;
    v.len = 0;
    v.max = 2;
    int *v_ = malloc(sizeof(int) * v.max);
    v.v = v_;
    return v;
}

void printVectorInfo(struct Vector v) {
    printf("len: %d, max: %d\n", v.len, v.max);
    printf("[");
    for (int i = 0; i < v.len; i++)
        printf("%d, ", v.v[i]);
    printf("]\n");
}

void add(struct Vector *v, int num) {
    v->v[v->len] = num;
    v->len++;

    // ベクタの要素数が上限の半分に達したら
    if (v->len * 2 >= v->max) {
        v->max *= 2;
        if (realloc(v->v, v->max) == NULL) {
           fprintf(stderr, "reallocation failed");
           exit(1);
        }
    }
}

int main() {
    struct Vector v = genVector();
    add(&v, 20);
    add(&v, 30);
    printVectorInfo(v);
    add(&v, 40);
    add(&v, 50);
    printVectorInfo(v);
}

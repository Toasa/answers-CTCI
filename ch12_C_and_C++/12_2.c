#include <stdio.h>
#include <string.h>

void swap(char *c1, char *c2) {
    char tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

// This function is destructive.
void rev(char *s) {
    int len = strlen(s);
    
    int l = 0;
    int r = len - 1;

    while (l < r) {
        swap(s+l, s+r);
        l++;
        r--;
    }
}

int main() {
    char s[] = "hello";
    rev(s);
    printf("%s\n", s);
}

#include <stdio.h>

int main() {
    int a, b, ret = 0, s = 0;
    while ((ret = scanf("%d%d", &a, &b)) == 2) {
//        printf("a = %d, b = %d\n", a, b);
        s += a*b;
    }
    if (ret == 1)
        printf("weird number of reads\n");
    printf("Result: %d\n", s);
    return 0;
}

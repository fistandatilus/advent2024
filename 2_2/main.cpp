#include <stdio.h>
#define LEN 1000

int main() {
    FILE *fp = fopen("input", "r");
    if (!fp) {
        printf("open error");
        return -1;
    }

    char *buf = new char[LEN];
    int a[LEN];
    int s = 0;
    size_t nn;

    while(getline(&buf, &nn, fp) > 1) {
        int n;
        char *bufp = buf;
        for (n = 0; sscanf(bufp, "%d", a+n) == 1; n++) {
            for (; *bufp >= '0' && *bufp <= '9'; bufp++);
            for (; *bufp == ' '; bufp++);
        }
        int good = 0;
        for (int i = -1; i < n && !good; i++) {
            int prevdiff = 0;
            int prev = a[i == 0 ? 1 : 0];
                good = 1;
            for (int j = (i == 0 || i == 1 ? 2 : 1); j < n; j++, j == i ? j++ : j){
                int diff = a[j] - prev;
                if (diff*prevdiff < 0 || diff == 0 || diff > 3 || diff < -3) {
                    good = 0;
                    break;
                }
                prevdiff = diff;
                prev = a[j];
            }
        }
        s += good;
    }

    printf("Result: %d\n", s);
}


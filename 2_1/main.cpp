#include <stdio.h>
#define LEN 1000

int main() {
    FILE *fp = fopen("input", "r");
    if (!fp) {
        printf("open error");
        return -1;
    }

    char *buf = new char[LEN];
    int s = 0;
    size_t n;

    while(getline(&buf, &n, fp) > 1) {
        printf("%s\n", buf);
        int prev;
        char *bufp = buf;
        if (sscanf(buf, "%d", &prev) != 1) {
            break;
        }
        
        for (;'0' <= *bufp && *bufp <= '9'; bufp++);
        for (;*bufp == ' '; bufp++);
        printf("%s", bufp);
        printf("prev = %d", prev);
        int cur, prevdiff = 0;
        printf("Start while 2\n");
        s++;
        while(sscanf(bufp, "%d", &cur) == 1) {
            printf("In while 2\n");
            printf("cur = %d, prev = %d\n", cur, prev);
            for (;'0' <= *bufp && *bufp <= '9'; bufp++);
            for (;*bufp == ' '; bufp++);
            int diff = cur - prev;
            if (prevdiff * diff < 0 || diff == 0 || diff > 3 || diff < -3) {
                s--;
                break;
            }
            prev = cur; 
            prevdiff = diff;
        }
    }

    printf("Result: %d\n", s);
}


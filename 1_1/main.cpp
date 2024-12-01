#include <stdio.h>
#define LEN 1000

void heapsort(int *a, int n);

int main() {
    FILE *fp = fopen("input", "r");
    if (!fp) {
        printf("open error");
        return -1;
    }

    int *a = new int[LEN];
    int *b = new int[LEN];

    for (int i = 0; i < LEN; i++)
        if (fscanf(fp, "%d%d", a+i, b+i) != 2) {
            printf("read error");
            return -1;
        }

    heapsort(a, LEN);
    heapsort(b, LEN);

    int s = 0;
    for (int i = 0; i < LEN; i++) {
        int d = a[i] - b[i];
        s += d > 0 ? d : -d;
    }

    printf("Result: %d\n", s);
    delete[] a;
    delete[] b;
}

void heapsort(int *a, int n)
{
    int i, j;
    int t;
    if (n < 2) return;
    for (i = 1; i < n; i++)
    {
        t = a[i];
        for (j = i; j > 0 && a[(j - 1)/2] < t; j = (j - 1)/2) a[j] = a[(j - 1)/2];
        a[j] = t;
    }
    for (i = n - 1; i > 1; i--)
    {
        t = a[i];
        a[i] = a[0];
        j = 0;
        while (2*j + 2 < i)
        {
            if (a[2*j + 1] > t && a[2*j + 1] >= a[2*j + 2])
            {
                a[j] = a[2*j + 1];
                j = 2*j + 1;
            }
            else if (a[2*j + 2] > t && a[2*j + 2] >= a[2*j + 1])
            {
                a[j] = a[2*j + 2];
                j = 2*j + 2;
            }
            else break;
        }
        if (2*j + 1 < i && t < a[2*j + 1])
        {
            a[j] = a[2*j + 1];
            j = 2*j + 1;
        }
        a[j] = t;
    }
    t = a[i];
    a[i] = a[0];
    a[0] = t;
}

#include <stdio.h>

int main() {
    int n, t, max = 0, min = 1000001;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        if (max < t) max = t;
        if (min > t) min = t;
    }

    printf("%d %d", min, max);
}
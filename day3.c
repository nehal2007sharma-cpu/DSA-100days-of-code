#include <stdio.h>

int main() {
    int n, k, i;
    int c = 0;
    int f = 0;

    scanf("%d", &n);

    int a[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        c++;
        if(a[i] == k) {
            printf("Found at index %d\n", i);
            f = 1;
            break;
        }
    }

    if(f == 0) {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", c);

    return 0;
}

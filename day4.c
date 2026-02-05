#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);

    int a[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int l = 0;
    int r = n - 1;
    int temp;

    while(l < r) {
        temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        l++;
        r--;
    }

    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

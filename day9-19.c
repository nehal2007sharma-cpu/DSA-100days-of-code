#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    // Input string
    scanf("%s", str);

    int len = strlen(str);

    // Print in reverse
    for(int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
day 10
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);

    int i = 0;
    int j = strlen(s) - 1;
    int isPalindrome = 1;

    while(i < j) {
        if(s[i] != s[j]) {
            isPalindrome = 0;
            break;
        }
        i++;
        j--;
    }

    if(isPalindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}
day 11
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int A[m][n], B[m][n], C[m][n];

    // Input first matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input second matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Addition
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Output result matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
day 12
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int A[m][n];

    // Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Check if square
    if(m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    int isSymmetric = 1;

    // Check symmetry
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] != A[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if(isSymmetric == 0) break;
    }

    if(isSymmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
day 13
#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int a[r][c];

    // Input
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while(top <= bottom && left <= right) {

        // 1. Left → Right
        for(int j = left; j <= right; j++) {
            printf("%d ", a[top][j]);
        }
        top++;

        // 2. Top → Bottom
        for(int i = top; i <= bottom; i++) {
            printf("%d ", a[i][right]);
        }
        right--;

        // 3. Right → Left
        if(top <= bottom) {
            for(int j = right; j >= left; j--) {
                printf("%d ", a[bottom][j]);
            }
            bottom--;
        }

        // 4. Bottom → Top
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                printf("%d ", a[i][left]);
            }
            left++;
        }
    }

    return 0;
}
day 14
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int A[n][n];
    int isIdentity = 1;

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Check identity condition
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j && A[i][j] != 1) {
                isIdentity = 0;
                break;
            }
            if(i != j && A[i][j] != 0) {
                isIdentity = 0;
                break;
            }
        }
        if(isIdentity == 0) break;
    }

    if(isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
day 15
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int A[m][n];

    // Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int sum = 0;

    // Sum of primary diagonal
    for(int i = 0; i < m && i < n; i++) {
        sum += A[i][i];
    }

    printf("%d", sum);

    return 0;
}
day 16
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int visited[n];  // to track counted elements

    // Input
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }

    // Frequency count
    for(int i = 0; i < n; i++) {

        if(visited[i] == 1)
            continue;

        int count = 1;

        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}
day 17
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Input
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    // Find max and min
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Max: %d\n", max);
    printf("Min: %d", min);

    return 0;
}
day 18
#include <stdio.h>

// Function to reverse part of array
void reverse(int arr[], int start, int end) {
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    // Handle k > n
    k = k % n;

    // Step 1: reverse whole array
    reverse(arr, 0, n - 1);

    // Step 2: reverse first k elements
    reverse(arr, 0, k - 1);

    // Step 3: reverse remaining
    reverse(arr, k, n - 1);

    // Output
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
day 19
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int x = 0, y = 0;

    // Step 2: Two pointer
    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            x = arr[left];
            y = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", x, y);

    return 0;
}

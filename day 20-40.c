day 20
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int prefixSum = 0;

    // Since values can be negative, we shift index
    int freq[20001] = {0};  // range handled by shifting
    int offset = 10000;

    // Initial condition (sum = 0)
    freq[offset] = 1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // If this sum seen before → add its frequency
        count += freq[prefixSum + offset];

        // Increase frequency
        freq[prefixSum + offset]++;
    }

    printf("%d", count);

    return 0;
}
day 21
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create linked list
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Traverse and print
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
day 22
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create linked list
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Count nodes
    int count = 0;
    temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}
day 23
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to merge two sorted lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;  // temporary start node
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while(l1 != NULL && l2 != NULL) {
        if(l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if(l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

// Function to print list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;

    // First list
    scanf("%d", &n);
    struct Node* list1 = createList(n);

    // Second list
    scanf("%d", &m);
    struct Node* list2 = createList(m);

    // Merge
    struct Node* result = mergeLists(list1, list2);

    // Output
    printList(result);

    return 0;
}
day 24
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;

    // Case 1: key is at head
    if(temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Traverse to find key
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if(temp == NULL)
        return head;

    // Delete node
    prev->next = temp->next;
    free(temp);

    return head;
}

// Print list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, key;

    scanf("%d", &n);
    struct Node* head = createList(n);

    scanf("%d", &key);

    head = deleteKey(head, key);

    printList(head);

    return 0;
}
day 25
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Count occurrences
int countKey(struct Node* head, int key) {
    int count = 0;

    while(head != NULL) {
        if(head->data == key) {
            count++;
        }
        head = head->next;
    }

    return count;
}

int main() {
    int n, key;

    scanf("%d", &n);
    struct Node* head = createList(n);

    scanf("%d", &key);

    int result = countKey(head, key);

    printf("%d", result);

    return 0;
}
day 28
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create circular linked list
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);

        if(head == NULL) {
            head = newNode;
            temp = newNode;
            newNode->next = head;  // circular link
        } else {
            temp->next = newNode;
            temp = newNode;
            temp->next = head;  // keep it circular
        }
    }

    // Traverse circular linked list
    if(head != NULL) {
        struct Node* curr = head;

        do {
            printf("%d ", curr->data);
            curr = curr->next;
        } while(curr != head);
    }

    return 0;
}
day 29
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Rotate right by k
struct Node* rotateRight(struct Node* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: find length
    int n = 1;
    struct Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Step 2: make circular
    temp->next = head;

    // Step 3: adjust k
    k = k % n;

    // Step 4: move to (n-k)th node
    int steps = n - k;
    struct Node* newTail = head;

    for(int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Step 5: set new head and break
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;

    scanf("%d", &n);
    struct Node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}
day 30
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create polynomial linked list
struct Node* createPoly(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d %d", &newNode->coeff, &newNode->exp);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Print polynomial
void printPoly(struct Node* head) {
    while(head != NULL) {

        if(head->exp == 0) {
            printf("%d", head->coeff);
        }
        else if(head->exp == 1) {
            printf("%dx", head->coeff);
        }
        else {
            printf("%dx^%d", head->coeff, head->exp);
        }

        if(head->next != NULL)
            printf(" + ");

        head = head->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* poly = createPoly(n);

    printPoly(poly);

    return 0;
}
day 31
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop
void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

// Display
void display() {
    if(top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);

        if(op == 1) {
            int val;
            scanf("%d", &val);
            push(val);
        }
        else if(op == 2) {
            pop();
        }
        else if(op == 3) {
            display();
        }
    }

    return 0;
}
day 32
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    stack[++top] = x;
}

// Pop
void pop() {
    if(top == -1) return; // avoid underflow
    top--;
}

int main() {
    int n;
    scanf("%d", &n);

    // Push elements
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    int m;
    scanf("%d", &m);

    // Perform m pops
    for(int i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack (top to bottom)
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
day 33
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    return stack[top--];
}

// Peek
char peek() {
    return stack[top];
}

// Precedence
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int k = 0;

    scanf("%s", infix);

    for(int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // Operand
        if(isalnum(ch)) {
            postfix[k++] = ch;
        }
        // Left parenthesis
        else if(ch == '(') {
            push(ch);
        }
        // Right parenthesis
        else if(ch == ')') {
            while(top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while(top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while(top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}
day 34
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    return stack[top--];
}

// Peek
char peek() {
    return stack[top];
}

// Precedence
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int k = 0;

    scanf("%s", infix);

    for(int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // Operand
        if(isalnum(ch)) {
            postfix[k++] = ch;
        }
        // Left parenthesis
        else if(ch == '(') {
            push(ch);
        }
        // Right parenthesis
        else if(ch == ')') {
            while(top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while(top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while(top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}
day 36
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if(front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = x;
}

// Dequeue
void dequeue() {
    if(front == -1) return;

    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display
void display() {
    if(front == -1) return;

    int i = front;
    while(1) {
        printf("%d ", queue[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Enqueue elements
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    int m;
    scanf("%d", &m);

    // Perform m dequeues
    for(int i = 0; i < m; i++) {
        dequeue();
    }

    // Display result
    display();

    return 0;
}
day 37
#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert
void insert(int x) {
    if(size < MAX) {
        pq[size++] = x;
    }
}

// Find index of minimum element
int findMinIndex() {
    if(size == 0) return -1;

    int minIndex = 0;
    for(int i = 1; i < size; i++) {
        if(pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete (remove min)
void deleteMin() {
    int minIndex = findMinIndex();

    if(minIndex == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[minIndex]);

    // Shift elements left
    for(int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Peek (show min)
void peek() {
    int minIndex = findMinIndex();

    if(minIndex == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[minIndex]);
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);

        if(op[0] == 'i') { // insert
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'd') { // delete
            deleteMin();
        }
        else if(op[0] == 'p') { // peek
            peek();
        }
    }

    return 0;
}
day 39
#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(int i) {
    while(i > 0) {
        int parent = (i - 1) / 2;

        if(heap[i] < heap[parent]) {
            swap(&heap[i], &heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

// Heapify Down
void heapifyDown(int i) {
    int smallest = i;

    while(1) {
        int left = 2*i + 1;
        int right = 2*i + 2;

        smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

// Insert
void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

// Peek
void peek() {
    if(size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);
}

// Extract Min
void extractMin() {
    if(size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", op);

        if(op[0] == 'i') {  // insert
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'e') {  // extractMin
            extractMin();
        }
        else if(op[0] == 'p') {  // peek
            peek();
        }
    }

    return 0;
}
day 40
#include <stdio.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function (Max Heap)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build Max Heap
void buildHeap(int arr[], int n) {
    for(int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Heap Sort
void heapSort(int arr[], int n) {

    // Step 1: Build Max Heap
    buildHeap(arr, n);

    // Step 2: Extract elements one by one
    for(int i = n - 1; i > 0; i--) {

        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    // Print sorted array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[n][n];

    // Initialize matrix with 0
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Read edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // For UNDIRECTED graph:
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Print adjacency matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
day 62
#include <stdio.h>
#include <stdlib.h>

// Node of adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected graph)
void addEdge(struct Node* adj[], int u, int v) {

    // Add v to u list
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    // Add u to v list
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Print adjacency list
void printGraph(struct Node* adj[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d -> ", i);

        struct Node* temp = adj[i];

        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    // Initialize all heads to NULL
    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    // Read edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
    }

    printGraph(adj, n);

    return 0;
}
day 63
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;

    node = createNode(u);
    node->next = adj[v];
    adj[v] = node;
}

// DFS function
void DFS(struct Node* adj[], int v, int visited[]) {

    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];

    while(temp != NULL) {
        int neighbor = temp->data;

        if(!visited[neighbor]) {
            DFS(adj, neighbor, visited);
        }

        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    // Read edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int start;
    scanf("%d", &start);

    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    DFS(adj, start, visited);

    return 0;
}
day 64
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected graph)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;

    node = createNode(u);
    node->next = adj[v];
    adj[v] = node;
}

// BFS function
void BFS(struct Node* adj[], int start, int n) {

    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int queue[n];
    int front = 0, rear = 0;

    // push source
    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear) {

        int curr = queue[front++];
        printf("%d ", curr);

        struct Node* temp = adj[curr];

        while(temp != NULL) {
            int neighbor = temp->data;

            if(!visited[neighbor]) {
                queue[rear++] = neighbor;
                visited[neighbor] = 1;
            }

            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    // edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int start;
    scanf("%d", &start);

    BFS(adj, start, n);

    return 0;
}
day 65
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;

    node = createNode(u);
    node->next = adj[v];
    adj[v] = node;
}

// DFS with parent tracking
int dfs(struct Node* adj[], int v, int visited[], int parent) {

    visited[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL) {
        int neighbor = temp->data;

        // not visited → go deeper
        if(!visited[neighbor]) {
            if(dfs(adj, neighbor, visited, v))
                return 1;
        }
        // visited and not parent → cycle
        else if(neighbor != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    // edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int cycle = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(adj, i, visited, -1)) {
                cycle = 1;
                break;
            }
        }
    }

    if(cycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}
day 66
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = v;
    node->next = NULL;
    return node;
}

// Add directed edge
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
}

// DFS helper
int dfs(struct Node* adj[], int v, int visited[], int recStack[]) {

    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL) {
        int neighbor = temp->data;

        // not visited → go deeper
        if(!visited[neighbor]) {
            if(dfs(adj, neighbor, visited, recStack))
                return 1;
        }
        // in recursion stack → cycle
        else if(recStack[neighbor]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[v] = 0; // backtrack
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    // directed edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[n], recStack[n];

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int cycle = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(adj, i, visited, recStack)) {
                cycle = 1;
                break;
            }
        }
    }

    if(cycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}
day 67
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = v;
    node->next = NULL;
    return node;
}

// Add directed edge
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
}

// DFS for topo sort
void topoDFS(struct Node* adj[], int v, int visited[], int stack[], int* top) {

    visited[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL) {
        int neighbor = temp->data;

        if(!visited[neighbor]) {
            topoDFS(adj, neighbor, visited, stack, top);
        }

        temp = temp->next;
    }

    // push to stack after visiting all neighbors
    stack[(*top)++] = v;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    // directed edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int stack[n];
    int top = 0;

    // run DFS for all nodes
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            topoDFS(adj, i, visited, stack, &top);
        }
    }

    // print reverse stack
    for(int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
day 70
#include <stdio.h>
#define INF 1000000000

// Edge structure
struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Edge edges[m];

    // Input edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u,
                          &edges[i].v,
                          &edges[i].w);
    }

    int dist[n];

    // Initialize distances
    for(int i = 0; i < n; i++)
        dist[i] = INF;

    int source = 0;
    dist[source] = 0;

    // Relax edges (n-1 times)
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {

            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycle
    for(int j = 0; j < m; j++) {

        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE");
            return 0;
        }
    }

    // Print distances
    for(int i = 0; i < n; i++) {
        if(dist[i] == INF)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    return 0;
}
day 71
#include <stdio.h>

#define EMPTY -1
#define DELETED -2

int hash(int key, int m) {
    return key % m;
}

// Insert using quadratic probing
void insert(int table[], int m, int key) {
    int h = hash(key, m);

    for(int i = 0; i < m; i++) {
        int idx = (h + i*i) % m;

        if(table[idx] == EMPTY || table[idx] == DELETED) {
            table[idx] = key;
            return;
        }
    }
}

// Search using quadratic probing
int search(int table[], int m, int key) {
    int h = hash(key, m);

    for(int i = 0; i < m; i++) {
        int idx = (h + i*i) % m;

        if(table[idx] == EMPTY)
            return 0; // stop early

        if(table[idx] == key)
            return 1;
    }

    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];

    // initialize
    for(int i = 0; i < m; i++)
        table[i] = EMPTY;

    for(int i = 0; i < q; i++) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if(op[0] == 'I') {
            insert(table, m, key);
        }
        else if(op[0] == 'S') {
            if(search(table, m, key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
day 72
#include <stdio.h>
#include <string.h>

int main() {
    char s[100000];
    scanf("%s", s);

    int visited[26] = {0};

    for(int i = 0; i < strlen(s); i++) {

        int idx = s[i] - 'a';

        if(visited[idx]) {
            printf("%c", s[i]);
            return 0;
        }

        visited[idx] = 1;
    }

    printf("-1");

    return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
    char s[100000];
    scanf("%s", s);

    int visited[26] = {0};

    for(int i = 0; i < strlen(s); i++) {

        int idx = s[i] - 'a';

        if(visited[idx]) {
            printf("%c", s[i]);
            return 0;
        }

        visited[idx] = 1;
    }

    printf("-1");

    return 0;
}
day 73
day 73
  #include <stdio.h>
#include <string.h>

int main() {
    char s[100000];
    scanf("%s", s);

    int freq[26] = {0};

    int n = strlen(s);

    // Step 1: count frequency
    for(int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: find first non-repeating
    for(int i = 0; i < n; i++) {
        if(freq[s[i] - 'a'] == 1) {
            printf("%c", s[i]);
            return 0;
        }
    }

    // if none found
    printf("$");

    return 0;
}
day 74
#include <stdio.h>
#include <string.h>

int main() {

    int n;
    scanf("%d", &n);

    char names[n][100];
    int freq[n];
    int count = 0;

    for(int i = 0; i < n; i++) {
        char temp[100];
        scanf("%s", temp);

        int found = 0;

        // check if already exists
        for(int j = 0; j < count; j++) {
            if(strcmp(names[j], temp) == 0) {
                freq[j]++;
                found = 1;
                break;
            }
        }

        // new candidate
        if(!found) {
            strcpy(names[count], temp);
            freq[count] = 1;
            count++;
        }
    }

    char winner[100] = "";
    int maxVotes = 0;

    for(int i = 0; i < count; i++) {

        if(freq[i] > maxVotes) {
            maxVotes = freq[i];
            strcpy(winner, names[i]);
        }
        else if(freq[i] == maxVotes) {
            if(strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}
dAY 75
#include <stdio.h>

#define MAX 100000

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // using simple prefix sum idea with brute optimization
    int maxLen = 0;

    for(int i = 0; i < n; i++) {

        int sum = 0;

        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(sum == 0) {
                int len = j - i + 1;
                if(len > maxLen)
                    maxLen = len;
            }
        }
    }

    printf("%d", maxLen);

    return 0;
}
DAY 78
  #include <stdio.h>

#define INF 1000000000

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int graph[n+1][n+1];

    // initialize graph
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    // input edges (undirected)
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int visited[n+1];
    int dist[n+1];

    for(int i = 1; i <= n; i++) {
        visited[i] = 0;
        dist[i] = INF;
    }

    // start from node 1
    dist[1] = 0;

    int totalWeight = 0;

    for(int i = 1; i <= n; i++) {

        int u = -1;
        int min = INF;

        // pick minimum unvisited node
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;
        totalWeight += dist[u];

        // update neighbors
        for(int v = 1; v <= n; v++) {
            if(graph[u][v] != INF && !visited[v] && graph[u][v] < dist[v]) {
                dist[v] = graph[u][v];
            }
        }
    }

    printf("%d", totalWeight);

    return 0;
}
DAY 79
  #include <stdio.h>

#define INF 1000000000

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int graph[n+1][n+1];

    // initialize graph
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    // input edges (undirected or directed both fine; here directed assumed)
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    int dist[n+1];
    int visited[n+1];

    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    int source;
    scanf("%d", &source);

    dist[source] = 0;

    for(int i = 1; i <= n; i++) {

        int u = -1;
        int min = INF;

        // pick minimum distance unvisited node
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // relax neighbors
        for(int v = 1; v <= n; v++) {
            if(graph[u][v] != INF && !visited[v]) {
                if(dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // print result
    for(int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}
DAY 80
  #include <stdio.h>

#define INF 1000000000

int main() {

    int n;
    scanf("%d", &n);

    int dist[n][n];

    // Input adjacency matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);

            if(x == -1 && i != j)
                dist[i][j] = INF;
            else
                dist[i][j] = x;
        }
    }

    // Floyd-Warshall
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(dist[i][k] != INF && dist[k][j] != INF) {

                    if(dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Print result
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
DAY 81
  #include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < n - 1; i++) {

        int swapped = 0;

        for(int j = 0; j < n - i - 1; j++) {

            if(a[j] > a[j + 1]) {

                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                swapped = 1;
            }
        }

        // optimization: stop if already sorted
        if(!swapped)
            break;
    }

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

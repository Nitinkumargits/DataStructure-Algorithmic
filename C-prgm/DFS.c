#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef struct Node
{
    int v;
    struct Node *next;
} Node;

Node *adj[N];
int visited[N];

void addEdge(int u, int v)
{
    Node *n = malloc(sizeof(Node));
    n->v = v;
    n->next = adj[u];
    adj[u] = n;
}

void dfs(int u)
{
    int stk[N], top = -1;
    stk[++top] = u;

    while (top >= 0)
    {
        u = stk[top--];
        if (!visited[u])
        {
            printf("%d ", u);
            visited[u] = 1;
            for (Node *p = adj[u]; p; p = p->next)
                if (!visited[p->v])
                    stk[++top] = p->v;
        }
    }
    printf("\n");
}

int main()
{
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(3, 5);
    addEdge(5, 6);
    addEdge(5, 7);
    dfs(1);
    return 0;
}

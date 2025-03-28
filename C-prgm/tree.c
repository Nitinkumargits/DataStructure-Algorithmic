#include <stdio.h>
#include <stdlib.h>

// Node structure for Binary Tree
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

// Queue Structure for Level Order Insertion
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

// Function Prototypes
void create(struct Queue *q, int size);
void enqueue(struct Queue *q, struct Node *x);
struct Node *dequeue(struct Queue *q);
int isEmpty(struct Queue q);

struct Node *root = NULL;

// Function to Create the Binary Tree
void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    if (!root)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);

        // Left Child
        printf("Enter left child of %d (-1 for NULL): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            if (!t)
            {
                printf("Memory allocation failed!\n");
                return;
            }
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        // Right Child
        printf("Enter right child of %d (-1 for NULL): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            if (!t)
            {
                printf("Memory allocation failed!\n");
                return;
            }
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

// Preorder Traversal
void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

// Inorder Traversal
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

// Postorder Traversal
void Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

// Queue Functions
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
    if (!q->Q)
    {
        printf("Queue memory allocation failed!\n");
        exit(1);
    }
}

void enqueue(struct Queue *q, struct Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if (q->front == q->rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

// Main Function
int main()
{
    Treecreate();

    printf("\nPreorder Traversal: ");
    Preorder(root);

    printf("\nInorder Traversal: ");
    Inorder(root);

    printf("\nPostorder Traversal: ");
    Postorder(root);

    return 0;
}

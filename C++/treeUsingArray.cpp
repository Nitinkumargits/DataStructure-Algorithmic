#include <iostream>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q; // Array of Node pointers

public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node *x);
    Node *dequeue();
};

// Constructor
Queue::Queue(int size)
{
    this->size = size;
    front = 0; // Start front at 0 for easier indexing
    rear = -1;
    Q = new Node *[size];
}

// Destructor
Queue::~Queue()
{
    delete[] Q;
}

// Check if queue is empty
bool Queue::isEmpty()
{
    return front > rear;
}

// Check if queue is full
bool Queue::isFull()
{
    return rear == size - 1;
}

// Enqueue function
void Queue::enqueue(Node *x)
{
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        Q[++rear] = x;
    }
}

// Dequeue function
Node *Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
        return nullptr;
    }
    return Q[front++];
}

// Global root node
Node *root = nullptr;

// Function to create a binary tree using level-order insertion
void createTree()
{
    Node *p;
    Node *t;
    int x;
    Queue q(10);

    cout << "Enter root value: ";
    cin >> x;

    root = new Node;
    if (!root)
    {
        cout << "Memory allocation failed!" << endl;
        return;
    }
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();

        // Left Child
        cout << "Enter left child of " << p->data << " (-1 for NULL): ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }

        // Right Child (Fixed Duplicate Prompt)
        cout << "Enter right child of " << p->data << " (-1 for NULL): ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

// Preorder Traversal
void preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

// Inorder Traversal
void inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

// Postorder Traversal
void postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}

// Cleanup function to delete nodes in a postorder manner
void destroyTree(Node *p)
{
    if (p)
    {
        destroyTree(p->lchild);
        destroyTree(p->rchild);
        delete p;
    }
}

// Main Function
int main()
{
    createTree();

    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    // Free allocated memory
    destroyTree(root);
    root = nullptr;

    return 0;
}

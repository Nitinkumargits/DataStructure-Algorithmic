#include <iostream>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;

    Node(int val) : data(val), lchild(nullptr), rchild(nullptr) {}
};

class BST
{
private:
    Node *root;
    void destroyTree(Node *p);

public:
    BST() { root = nullptr; }
    ~BST() { destroyTree(root); }

    Node *getRoot() { return root; }
    void Insert(int key);
    void Inorder(Node *p);
    Node *Search(int key);
};

void BST::Insert(int key)
{
    Node *t = root;
    Node *r = nullptr; // Parent node
    Node *p;

    if (root == nullptr)
    {
        root = new Node(key);
        return;
    }

    while (t != nullptr)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }

    p = new Node(key);
    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

void BST::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

Node *BST::Search(int key)
{
    Node *t = root;
    while (t != nullptr)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return nullptr;
}

void BST::destroyTree(Node *p)
{
    if (p)
    {
        destroyTree(p->lchild);
        destroyTree(p->rchild);
        delete p;
    }
}

int main()
{
    BST bst;

    // Insert
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(20);
    bst.Insert(8);
    bst.Insert(30);

    // Inorder traversal
    bst.Inorder(bst.getRoot());
    cout << endl;

    // Search
    Node *temp = bst.Search(2);
    if (temp != nullptr)
    {
        cout << "Found: " << temp->data << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}

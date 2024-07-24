#include <stdio.h>
#include <stdlib.h>

// Utility function to find the maximum of two integers
int max(int x, int y)
{
    return (x > y) ? x : y;
}

// Data structure to store a binary tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to allocate memory for a binary tree node
struct Node *allocateNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to calculate the height of a binary tree with
// leaf nodes forming a circular doubly linked list
int height(struct Node *node)
{
    // base case: if the node is NULL
    if (node == NULL)
    {
        return 0;
    }

    // node is a leaf if its left's right and right's left
    // are pointing to the node itself
    if ((node->left && node->left->right == node) &&
        (node->right && node->right->left == node))
    {
        return 1;
    }

    // recur for the left and right subtree and consider maximum depth
    return 1 + max(height(node->left), height(node->right));
}

int main(void)
{
    struct Node *root = NULL;

    // construct the tree
    root = allocateNode(1);
    root->left = allocateNode(2);
    root->right = allocateNode(3);
    root->left->left = allocateNode(4);
    root->left->right = allocateNode(5);      // leaf node
    root->right->right = allocateNode(6);     // leaf node
    root->left->left->left = allocateNode(7); // leaf node

    // construct a circular doubly linked list from leaves
    struct Node *first = root->left->left->left;
    struct Node *second = root->left->right;
    struct Node *third = root->right->right;

    // set previous and next pointers of the linked list
    // (left and right pointer of a binary tree node, respectively)
    first->left = third;
    first->right = second;

    second->left = first;
    second->right = third;

    third->left = second;
    third->right = first;

    printf("The height of the binary tree is %d", height(root));

    return 0;
}
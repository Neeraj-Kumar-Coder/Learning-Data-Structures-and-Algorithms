#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *insertNode(struct Node *root, int value);
struct Node *deleteNode(struct Node *root, int value);
void preOrderTraversal(struct Node *root);
void inOrderTraversal(struct Node *root);
void postOrderTraversal(struct Node *root);

int main(void)
{
    // Creating the root node
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = 100;
    root->left = root->right = NULL;

    int number_of_nodes, value;
    printf("How many nodes do you want to add in the BST?: ");
    scanf("%d", &number_of_nodes);

    while (number_of_nodes--)
    {
        printf("Enter the value: ");
        scanf("%d", &value);
        insertNode(root, value);
    }

    inOrderTraversal(root);
    return 0;
}

struct Node *insertNode(struct Node *root, int value)
{
    if (!root) // Guard clause
        return NULL;

    struct Node *previous = NULL; // Follower pointer

    while (root) // Searching the correct position for insertion
    {
        previous = root;
        if (root->data < value)
        {
            root = root->right;
        }
        else if (root->data > value)
        {
            root = root->left;
        }
        else
        {
            return root; // Returns the function as value is already present
        }
    }

    // Inserting at the correct position
    if (previous->data > value)
    {
        previous->left = (struct Node *)malloc(sizeof(struct Node));
        (previous->left)->data = value;
        (previous->left)->left = (previous->left)->right = NULL;
        return previous->left;
    }
    else
    {
        previous->right = (struct Node *)malloc(sizeof(struct Node));
        (previous->right)->data = value;
        (previous->right)->left = (previous->right)->right = NULL;
        return previous->right;
    }
}

struct Node *deleteNode(struct Node *root, int value)
{
    ;
}

void preOrderTraversal(struct Node *root) // Root -> Left subtree -> Right subtree
{
    if (!root) // Guard clause
        return;

    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(struct Node *root) // Left subtree -> Root -> Right subtree
{
    if (!root) // Guard clause
        return;

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void postOrderTraversal(struct Node *root) // Right subtree -> Left subtree -> Root
{
    if (!root) // Guard clause
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}
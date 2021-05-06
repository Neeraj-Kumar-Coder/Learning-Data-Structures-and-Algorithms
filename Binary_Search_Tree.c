#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int isBST(struct Node *root);

int main(void)
{
    // CREATING NODES
    struct Node *root = createNode(4);
    struct Node *child_1 = createNode(2);
    struct Node *child_2 = createNode(6);
    struct Node *child_3 = createNode(1);
    struct Node *child_4 = createNode(3);
    struct Node *child_5 = createNode(5);
    struct Node *child_6 = createNode(7);

    // LINKING NODES
    root->left = child_1;
    root->right = child_2;
    child_1->left = child_3;
    child_1->right = child_4;
    child_2->left = child_5;
    child_2->right = child_6;

    // CHECKING IF IT IS A BST OR NOT
    printf("Is BST = %d\n", isBST(root));
    return 0;
}

int isBST(struct Node *root)
{
    static struct Node *previous = NULL;
    if (root)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (previous && root->data <= previous->data)
        {
            return 0;
        }
        previous = root;
        return isBST(root->right);
    }
    return 1;
}
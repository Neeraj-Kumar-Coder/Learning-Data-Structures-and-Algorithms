/*
    CREATING THIS BINARY TREE:
                root
             //      \\
            //        \\
        child_1       child_2
        //  \\       //      \\
    child_3 child_4 child_5 child_6

                5
              /  \
            4     3
          /  \   / \
         2   1  2   3

*/
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

void preOrderTraversal(struct Node *root);
void postOrderTraversal(struct Node *root);
void inOrderTraversal(struct Node *root);

int main(void)
{
    // CREATING NODES
    struct Node *root = createNode(5);
    struct Node *child_1 = createNode(4);
    struct Node *child_2 = createNode(3);
    struct Node *child_3 = createNode(2);
    struct Node *child_4 = createNode(1);
    struct Node *child_5 = createNode(2);
    struct Node *child_6 = createNode(3);

    // LINKING NODES
    root->left = child_1;
    root->right = child_2;
    child_1->left = child_3;
    child_1->right = child_4;
    child_2->left = child_5;
    child_2->right = child_6;

    preOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    printf("\n");
    inOrderTraversal(root);
    return 0;
}

void preOrderTraversal(struct Node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node *root)
{
    if (root)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void inOrderTraversal(struct Node *root)
{
    if (root)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
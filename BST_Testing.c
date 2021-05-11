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
void inOrderTraversal(struct Node *root);
struct Node *inOrderSuccessor(struct Node *root, int key);

int main(void)
{
    // CREATING NODES
    struct Node *root = createNode(50);
    struct Node *child_1 = createNode(40);
    struct Node *child_2 = createNode(55);
    struct Node *child_3 = createNode(30);
    struct Node *child_4 = createNode(42);
    struct Node *child_5 = createNode(51);
    struct Node *child_6 = createNode(60);
    struct Node *child_7 = createNode(20);
    struct Node *child_8 = createNode(35);
    struct Node *child_9 = createNode(45);
    struct Node *child_10 = createNode(53);
    struct Node *child_11 = createNode(70);
    struct Node *child_12 = createNode(52);
    struct Node *child_13 = createNode(54);

    // LINKING NODES
    root->left = child_1;
    root->right = child_2;
    child_1->left = child_3;
    child_1->right = child_4;
    child_2->left = child_5;
    child_2->right = child_6;
    child_3->left = child_7;
    child_3->right = child_8;
    child_4->right = child_9;
    child_5->right = child_10;
    child_6->right = child_11;
    child_10->left = child_12;
    child_10->right = child_13;

    // CHECKING IF IT IS A BST OR NOT
    printf("Is BST = %d\n", isBST(root));
    inOrderTraversal(root);
    printf("\n");

    int key = 45;

    printf("The InOrderSuccessor of %d is %d\n", key, inOrderSuccessor(root, key)->data);
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

void inOrderTraversal(struct Node *root) // Left subtree -> Root -> Right subtree
{
    if (root)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

struct Node *inOrderSuccessor(struct Node *root, int key)
{
    if (!root)
        return root;

    struct Node *successor = NULL;
    while (root)
    {
        if (root->data > key)
            successor = root, root = root->left;
        else if (root->data < key)
            root = root->right;
        else
        {
            if (root->right)
            {
                root = root->right;
                while (root->left)
                    root = root->left;
                successor = root;
            }
            break;
        }
    }
    return successor;
}
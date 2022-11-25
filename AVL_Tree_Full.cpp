#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct AVL_Node
{
    T value;
    AVL_Node<T> *left, *right;
    int height, sizeOfSubtree;

    AVL_Node(void)
    {
        this->left = this->right = nullptr;
        this->height = 0;
        this->sizeOfSubtree = 1;
    }

    AVL_Node(T value)
    {
        this->left = this->right = nullptr;
        this->value = value;
        this->height = 0;
        this->sizeOfSubtree = 1;
    }

    AVL_Node(T value, AVL_Node<T> *left, AVL_Node<T> *right)
    {
        left = nullptr;
        this->left = left;
        this->right = right;
        this->height = max(left ? left->height : -1, right ? right->height : -1) + 1;
        this->sizeOfSubtree = (left ? left->sizeOfSubtree : 0) + (right ? right->sizeOfSubtree : 0) + 1;
    }
};

template <typename T>
class AVL_Tree
{
private:
    AVL_Node<T> *root;

    int getHeight(AVL_Node<T> *node)
    {
        if (!node)
            return -1;
        return node->height;
    }

    int getBalanceFactor(AVL_Node<T> *node)
    {
        if (!node)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

public:
    AVL_Tree(void)
    {
        root = nullptr;
    }
};

int main(void)
{
    AVL_Tree<int> tree;
    return 0;
}
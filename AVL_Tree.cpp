#include <iostream>

using namespace std;

template <class type>
class NodeForAVLTree
{
public:
    type key;
    int height;
    NodeForAVLTree<type> *left;
    NodeForAVLTree<type> *right;
    NodeForAVLTree() {}
    NodeForAVLTree(type value)
    {
        key = value;
        height = 0;
        left = right = NULL;
    }
};

template <class type>
class AVLTree
{
private:
    NodeForAVLTree<type> *root;
    int getHeight(NodeForAVLTree<type> *node)
    {
        if (!node)
        {
            return -1;
        }
        return node->height;
    }

    int getBalanceFactor(NodeForAVLTree<type> *node)
    {
        if (!node)
        {
            return 0;
        }
        return getHeight(node->right) - getHeight(node->left);
    }

    NodeForAVLTree<type> *leftRotate(NodeForAVLTree<type> *Y)
    {
        NodeForAVLTree<type> *X = Y->right;
        NodeForAVLTree<type> *T2 = X->left;
        Y->right = T2;
        X->left = Y;

        Y->height = max(getHeight(Y->left), getHeight(Y->right)) + 1;
        X->height = max(getHeight(X->left), getHeight(X->right)) + 1;
        return X;
    }

    NodeForAVLTree<type> *rightRotate(NodeForAVLTree<type> *X)
    {
        NodeForAVLTree<type> *Y = X->left;
        NodeForAVLTree<type> *T2 = Y->right;
        X->left = T2;
        Y->right = X;

        X->height = max(getHeight(X->left), getHeight(X->right)) + 1;
        Y->height = max(getHeight(Y->left), getHeight(Y->right)) + 1;
        return Y;
    }

    NodeForAVLTree<type> *insert(NodeForAVLTree<type> *node, type key)
    {
        if (!node)
        {
            return new NodeForAVLTree<type>(key);
        }
        if (node->key > key)
        {
            node->left = insert(node->left, key);
        }
        else
        {
            node->right = insert(node->right, key);
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balanceFactor = getBalanceFactor(node);

        // LL Rotation
        if (balanceFactor < -1 && key < node->left->key)
        {
            return rightRotate(node);
        }
        // LR Rotation
        else if (balanceFactor < -1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // RR Rotation
        else if (balanceFactor > 1 && key > node->right->key)
        {
            return leftRotate(node);
        }
        // RL Rotation
        else if (balanceFactor > 1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void preOrder(NodeForAVLTree<type> *node)
    {
        if (!node)
        {
            return;
        }
        cout << node->key << ' ';
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(NodeForAVLTree<type> *node)
    {
        if (!node)
        {
            return;
        }
        inOrder(node->left);
        cout << node->key << ' ';
        inOrder(node->right);
    }

    void postOrder(NodeForAVLTree<type> *node)
    {
        if (!node)
        {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        cout << node->key << ' ';
    }

public:
    AVLTree(void)
    {
        root = NULL;
    }

    void insert(type key)
    {
        if (!root)
        {
            root = new NodeForAVLTree<type>(key);
            return;
        }
        root = insert(root, key);
    }

    void preOrder(void)
    {
        preOrder(root);
        cout << '\n';
    }

    void inOrder(void)
    {
        inOrder(root);
        cout << '\n';
    }

    void postOrder(void)
    {
        postOrder(root);
        cout << '\n';
    }
};

int main(void)
{
    int numberOfKeys, key;
    cout << "Enter the number of keys you want to inset in the AVL Tree: ";
    cin >> numberOfKeys;

    AVLTree<int> myAVLTree;
    while (numberOfKeys--)
    {
        cout << "Enter the key: ";
        cin >> key;
        myAVLTree.insert(key);
    }

    cout << "The preOrder traversal of the tree is: ";
    myAVLTree.preOrder();

    cout << "The inorder traversal of the tree is: ";
    myAVLTree.inOrder();

    cout << "The postOrder traversal of the tree is: ";
    myAVLTree.postOrder();
    return 0;
}
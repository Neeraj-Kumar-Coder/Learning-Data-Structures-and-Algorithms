#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *buildTreeUtil(vector<int> &inorder, vector<int> &postorder, int il, int ih, int pl, int ph)
    {
        if (il > ih || pl > ph)
            return nullptr;

        int rootVal = postorder[ph];
        TreeNode *root = new TreeNode(rootVal);

        int i;
        for (i = il; i <= ih; i++)
            if (inorder[i] == rootVal)
                break;

        int sizeofleftsubtree = i - il;
        int sizeofrightsubtree = ih - i;
        root->left = buildTreeUtil(inorder, postorder, il, i - 1, pl, pl + sizeofleftsubtree - 1);
        root->right = buildTreeUtil(inorder, postorder, i + 1, ih, pl + sizeofleftsubtree, ph - 1);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int rootVal = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootVal);

        int i;
        for (i = 0; i < inorder.size(); i++)
            if (inorder[i] == rootVal)
                break;

        root->left = buildTreeUtil(inorder, postorder, 0, i - 1, 0, i - 1);
        root->right = buildTreeUtil(inorder, postorder, i + 1, inorder.size() - 1, i, postorder.size() - 2);

        return root;
    }
};

int main(void)
{
    vector<int> inorder = {11, 2, 7, 3, 9, 10, 13, 15};
    vector<int> postorder = {11, 7, 2, 10, 15, 13, 9, 3};
    Solution obj;
    obj.buildTree(inorder, postorder);
    return 0;
}
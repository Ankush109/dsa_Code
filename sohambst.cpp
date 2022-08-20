#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool searchRecursive(TreeNode *root, int val)
{
    if (!root)
        return false;
    if (root->data == val)
        return true;
    if (root->data < val)
        return searchRecursive(root->right, val);
    return searchRecursive(root->left, val);
}

TreeNode *insertRecursive(TreeNode *root, int val)
{
    if (!root)
    {
        TreeNode *node = new TreeNode(val);
        return node;
    }
    if (root->data < val)
    {
        root->right = insertRecursive(root->right, val);
        return root;
    }
    root->left = insertRecursive(root->left, val);
    return root;
}
bool isLeafNode(TreeNode *root)
{
    return (root->left == NULL && root->right == NULL);
}

TreeNode *findAndDeleteInorderSuccessor(TreeNode *root, int &val)
{
    if (!root->left)
    {
        val = root->data;
        TreeNode *right = root->right;
        delete root;
        return right;
    }
    root->left = findAndDeleteInorderSuccessor(root->left, val);
    return root;
}

TreeNode *findAndDeleteInorderPredecessor(TreeNode *root, int &val)
{
    if (!root->right)
    {
        val = root->data;
        TreeNode *left = root->left;
        delete root;
        return left;
    }
    root->right = findAndDeleteInorderPredecessor(root->right, val);
    return root;
}
TreeNode *deleteRecursive(TreeNode *root, int val)
{
    if (root->data < val)
    {
        root->right = deleteRecursive(root->right, val);
        return root;
    }
    else if (root->data > val)
    {
        root->left = deleteRecursive(root->left, val);
        return root;
    }
    if (isLeafNode(root))
    {
        TreeNode *todelete = root;
        delete todelete;
        return NULL;
    }
    if (root->right)
    {
        // finding inorder successor
        int inordereSuccessorValue = -1;
        root->right = findAndDeleteInorderSuccessor(root->right, inordereSuccessorValue);
        root->data = inordereSuccessorValue;
    }
    else
    {
        // finding inorder predecessor
        int inorderPredecessorValue = -1;
        root->left = findAndDeleteInorderPredecessor(root->left, inorderPredecessorValue);
        root->data = inorderPredecessorValue;
    }
    return root;
}

void inordereTraversal(TreeNode *root)
{
    if (!root)
        return;
    inordereTraversal(root->left);
    cout << root->data << " ";
    inordereTraversal(root->right);
}

int main()
{
    TreeNode *root = NULL;
    root = insertRecursive(root, 10);
    root = insertRecursive(root, 5);
    root = insertRecursive(root, 15);
    root = insertRecursive(root, 7);
    inordereTraversal(root);
    cout << "\n";
    root = insertRecursive(root, 12);
    inordereTraversal(root);
    cout << "\n";
    cout << searchRecursive(root, 12) << "\n";
    cout << searchRecursive(root, 1) << "\n";
    root = deleteRecursive(root, 15);
    inordereTraversal(root);
    cout << "\n";
    root = deleteRecursive(root, 5);
    inordereTraversal(root);
    cout << "\n";
}
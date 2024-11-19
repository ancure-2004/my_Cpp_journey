#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inOrder(TreeNode<int> *root, vector<int> &ans)
{

    if (root == NULL)
        return;

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> ans;
    inOrder(root, ans);
    int size = ans.size();
    TreeNode<int> *newRoot = new TreeNode<int>(ans[0]);
    TreeNode<int> *curr = newRoot;

    for (int i = 1; i < size; i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(ans[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

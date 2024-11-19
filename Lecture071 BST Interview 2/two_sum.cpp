#include <bits/stdc++.h>
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

};
***************/
void inOrder(BinaryTreeNode<int> *root, vector<int> &ans)
{

    if (root == NULL)
        return;

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

bool twoSumInBST(BinaryTreeNode<int> *root, int target)
{

    vector<int> ans;
    inOrder(root, ans);

    int i = 0;
    int j = ans.size() - 1;
    int sum = 0;

    while (i < j)
    {

        sum = ans[i] + ans[j];

        if (sum == target)
            return true;

        if (sum < target)
            i++;

        if (sum > target)
            j--;
    }

    return false;
}
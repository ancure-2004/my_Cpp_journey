TreeNode *find(TreeNode *curr)
{
    TreeNode *pred = curr->left;
    while (pred->right != NULL && pred->right != curr)
    {
        pred = pred->right;
    }
    return pred;
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            TreeNode *pred = find(curr);
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}
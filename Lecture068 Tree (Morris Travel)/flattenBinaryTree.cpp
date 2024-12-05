void flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            TreeNode<int> *pred = curr->left;
            while (pred->right)
                pred = pred->right;

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
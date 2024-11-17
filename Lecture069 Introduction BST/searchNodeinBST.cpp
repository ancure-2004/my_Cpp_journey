bool searchInBST(BinaryTreeNode<int> *root, int x)
{

    BinaryTreeNode<int> *curr = root;

    while (curr != NULL)
    {

        if (x == curr->data)
        {
            return true;
        }

        else if (x < curr->data)
        {
            curr = curr->left;
        }

        else
        {
            curr = curr->right;
        }
    }
    return false;
}
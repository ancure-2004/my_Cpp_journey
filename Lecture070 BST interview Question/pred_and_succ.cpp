pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(NULL, NULL);
        return p;
    }

    TreeNode *temp = root;
    int pred = -1;
    int succ = -1;

    while (temp != NULL)
    {
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }

        else if (temp->data == key)
            break;

        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    if (temp == NULL)
    {
        return make_pair(pred, succ);
    }

    TreeNode *leftTree = temp->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    TreeNode *rightTree = temp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}
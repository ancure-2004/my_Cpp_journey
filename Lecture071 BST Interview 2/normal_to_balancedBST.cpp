/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inorder(TreeNode<int> *root, vector<int> &ans)
{

    if (root == NULL)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

TreeNode<int> *solve(vector<int> &ans, int s, int e)
{

    if (s > e)
        return NULL;

    int mid = (s + e) / 2;

    TreeNode<int> *newRoot = new TreeNode<int>(ans[mid]);

    newRoot->left = solve(ans, s, mid - 1);
    newRoot->right = solve(ans, mid + 1, e);

    return newRoot;
}

TreeNode<int> *balancedBst(TreeNode<int> *root)
{

    vector<int> ans;
    inorder(root, ans);
    int s = 0;
    int e = ans.size() - 1;
    TreeNode<int> *ansNode = solve(ans, s, e);

    return ansNode;
}

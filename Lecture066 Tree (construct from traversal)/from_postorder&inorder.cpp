class Solution
{
public:
    void createmapping(vector<int> inorder, int n, map<int, int> &nodetoindex)
    {

        for (int i = 0; i < n; i++)
        {
            nodetoindex[inorder[i]] = i;
        }
    }

    Node *solve(vector<int> inorder, vector<int> postorder, int &index,
                int n, int s, int e, map<int, int> &nodetoindex)
    {

        if (index < 0 || s > e)
            return NULL;

        int element = postorder[index--];
        Node *root = new Node(element);
        int position = nodetoindex[element];

        root->right = solve(inorder, postorder, index, n, position + 1, e, nodetoindex);
        root->left = solve(inorder, postorder, index, n, s, position - 1, nodetoindex);

        return root;
    }

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(vector<int> inorder, vector<int> postorder)
    {

        int n = inorder.size();
        int postorderindex = n - 1;

        map<int, int> nodetoindex;
        createmapping(inorder, n, nodetoindex);

        Node *ans = solve(inorder, postorder, postorderindex, n, 0, n - 1, nodetoindex);

        return ans;
    }
};
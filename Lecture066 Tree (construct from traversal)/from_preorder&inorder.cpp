class Solution
{
public:
    void createMapping(vector<int> inorder, map<int, int> &nodeToindex, int n)
    {

        for (int i = 0; i < n; i++)
        {
            nodeToindex[inorder[i]] = i;
        }
    }

    Node *solve(vector<int> inorder, vector<int> preorder, int &index,
                int s, int e, int n, map<int, int> &nodeToindex)
    {

        if (index >= n || s > e)
        {
            return NULL;
        }

        int element = preorder[index++];
        Node *root = new Node(element);
        int position = nodeToindex[element];

        root->left = solve(inorder, preorder, index, s, position - 1, n, nodeToindex);
        root->right = solve(inorder, preorder, index, position + 1, e, n, nodeToindex);

        return root;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &preorder)
    {

        int preOrderIndex = 0;
        int n = inorder.size();
        map<int, int> nodeToindex;

        createMapping(inorder, nodeToindex, n);
        Node *ans = solve(inorder, preorder, preOrderIndex, 0, n - 1, n, nodeToindex);

        return ans;
    }
};
class Solution
{
public:
    void inOrder(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        inOrder(root->left, ans);
        ans.push_back(root->data);
        inOrder(root->right, ans);
    }

    vector<int> mergingBST(vector<int> &a, vector<int> &b)
    {

        vector<int> ans(a.size() + b.size());
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < a.size() && j < b.size())
        {
            if (a[i] < b[j])
            {
                ans[k++] = a[i];
                i++;
            }

            else
            {
                ans[k++] = b[j];
                j++;
            }
        }

        while (i < a.size())
        {
            ans[k++] = a[i];
            i++;
        }

        while (j < b.size())
        {
            ans[k++] = b[j];
            j++;
        }
        return ans;
    }

    Node *inOrderToBST(int s, int e, vector<int> &merged)
    {
        if (s > e)
            return NULL;

        int mid = (s + e) / 2;
        Node *root = new Node(merged[mid]);
        root->left = inOrderToBST(s, mid - 1, merged);
        root->right = inOrderToBST(mid + 1, e, merged);

        return root;
    }
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> BST1;
        vector<int> BST2;

        inOrder(root1, BST1);
        inOrder(root2, BST2);

        vector<int> merged = mergingBST(BST1, BST2);

        int s = 0;
        int e = merged.size() - 1;

        Node *ans = inOrderToBST(s, e, merged);
        vector<int> ansArray;
        inOrder(ans, ansArray);

        return ansArray;
    }
};
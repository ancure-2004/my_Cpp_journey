#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{

    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }

    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeinput(Node *&root)
{

    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{

    queue<Node *> q;
    q.push(root);
    q.push(NULL); // Seperator

    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {

            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {

            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inOrder(Node *root)
{

    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{

    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{

    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int max(Node *root)
{

    Node *temp = root;
    while (temp->right != NULL)
        temp = temp->right;

    return temp->data;
}

int min(Node *root)
{

    Node *temp = root;
    while (temp->left != NULL)
        temp = temp->left;

    return temp->data;
}

Node *deleteFromBST(Node *root, int n)
{
    // Base Case
    if (root == NULL)
        return root;

    if (root->data == n)
    {

        // Case 1
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2

        // Left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Right Child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // Case 3
        if (root->left != NULL && root->right != NULL)
        {
            int mini = min(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    else if (root->data > n)
    {
        root->left = deleteFromBST(root->left, n);
        return root;
    }

    else
    {
        root->right = deleteFromBST(root->right, n);
        return root;
    }
}

int main()
{
    Node *root = NULL;

    cout << "Enter the data for BST" << endl;
    takeinput(root);

    cout << "Printing BST" << endl;
    levelOrderTraversal(root);

    // cout << "Printing InOrder" << endl;
    // inOrder(root);

    // cout << endl
    //      << "Printing PreOrder" << endl;
    // preOrder(root);

    // cout << endl
    //      << "Printing PostOrder" << endl;
    // postOrder(root);

    // cout << endl;

    // cout << "The max of tree is: " << max(root) << endl;

    // cout << "The min of tree is: " << min(root) << endl;

    root = deleteFromBST(root, 50);

    cout << "Printing BST" << endl;
    levelOrderTraversal(root);

    return 0;
}
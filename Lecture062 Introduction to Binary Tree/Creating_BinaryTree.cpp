#include <iostream>
#include <queue>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

public:
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Entering data for left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Entering data for right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL); // Seperator

    while (!q.empty())
    {

        node *temp = q.front();
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

void buildfromLevelOrder(node *&root)
{

    queue<node *> q;

    cout << "Enter data for root node: " << endl;
    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        cout << "Enter data for left node of " << temp->data << endl;
        int leftNode;
        cin >> leftNode;

        if (leftNode != -1)
        {
            temp->left = new node(leftNode);
            q.push(temp->left);
        }

        cout << "Enter data for right node of " << temp->data << endl;
        int rightNode;
        cin >> rightNode;

        if (rightNode != -1)
        {
            temp->right = new node(rightNode);
            q.push(temp->right);
        }
    }
}

void inOrder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;

    buildfromLevelOrder(root);
    preorderTraversal(root);

    // // Creating Binary Tree
    // root = buildTree(root);

    // cout << "Printing the level order tracersal output " << endl;
    // levelOrderTraversal(root);

    // cout << endl
    //      << "Printing InOrder traversal" << endl;
    // inOrder(root);

    // cout << endl
    //      << "Printing PreOrder traversal" << endl;
    // preOrder(root);

    // cout << endl
    //      << "Printing InOrder traversal" << endl;
    // postOrder(root);

    return 0;
}

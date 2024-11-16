#include <bits/stdc++.h>

BinaryTreeNode<int> *createmapping(BinaryTreeNode<int> *root,
                                   int target, map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &nodeToparent)
{

    BinaryTreeNode<int> *res = NULL;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    nodeToparent[root] = NULL;
    while (!q.empty())
    {

        BinaryTreeNode<int> *front = q.front();
        q.pop();

        if (front->data == target)
        {
            res = front;
        }

        if (front->left)
        {
            nodeToparent[front->left] = front;
            q.push(front->left);
        }

        if (front->right)
        {
            nodeToparent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

void burnTree(BinaryTreeNode<int> *root, int &ans, map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &nodeToparent)
{

    map<BinaryTreeNode<int> *, bool> visited;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    visited[root] = 1;

    while (!q.empty())
    {

        int size = q.size();
        bool flag = 0;

        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }

            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            if (nodeToparent[front] && !visited[nodeToparent[front]])
            {
                flag = 1;
                q.push(nodeToparent[front]);
                visited[nodeToparent[front]] = 1;
            }
        }

        if (flag == 1)
            ans++;
    }
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    int ans = 0;
    map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> nodeToparent;
    BinaryTreeNode<int> *targetNode = createmapping(root, start, nodeToparent);

    burnTree(targetNode, ans, nodeToparent);

    return ans;
}
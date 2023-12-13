#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    int height(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        int height = 0;
        int previous_nodes = 0;
        while (not q.empty())
        {
            if (q.front()->left != NULL)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right != NULL)
            {
                q.push(q.front()->right);
            }
            if (previous_nodes != 2 and (q.front()->left != NULL or q.front()->right != NULL))
            {
                ++height;
            }
            previous_nodes = 0;
            if (q.front()->left != NULL)
                ++previous_nodes;
            if (q.front()->right != NULL)
                ++previous_nodes;

            q.pop();
        }
        return height;
    }
};

int main()
{
    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    cin >> t;

    while (t-- > 0)
    {
        cin >> data;
        root = myTree.insert(root, data);
    }

    int height = myTree.height(root);

    cout << height;

    return 0;
}
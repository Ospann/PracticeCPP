#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int SumLeaves(TreeNode *tree)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return root->val;
    }

    int leftSum = SumLeaves(root->left);
    int rightSum = SumLeaves(root->right);

    return leftSum + rightSum;
}

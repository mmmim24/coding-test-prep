#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return valid(root, LONG_MIN, LONG_MAX);
    }

    bool valid(TreeNode *node, long left, long right)
    {
        if (!node)
        {
            return true;
        }
        if (node->val <= left || node->val >= right)
        {
            return false;
        }
        return valid(node->left, left, node->val) && valid(node->right, node->val, right);
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    left->left = new TreeNode(4);
    left->right = new TreeNode(5);
    TreeNode *right = new TreeNode(3);
    right->left = new TreeNode(6);
    right->right = new TreeNode(7);
    root->left = left, root->right = right;

    Solution s;
    s.isValidBST(root) ? cout << "Valid\n" : cout << "Not Valid\n";

    root = new TreeNode(4);
    left = new TreeNode(2);
    left->left = new TreeNode(1);
    left->right = new TreeNode(3);
    right = new TreeNode(6);
    right->left = new TreeNode(5);
    right->right = new TreeNode(7);
    root->left = left, root->right = right;

    s.isValidBST(root) ? cout << "Valid\n" : cout << "Not Valid\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
/**
Definition for a binary tree node.
*/
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return targetSum == root->val;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
int main()
{
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(2);
    TreeNode *root = new TreeNode(1, left, right);
    left->left = new TreeNode(3);
    left->right = new TreeNode(4);
    right->left = new TreeNode(4);
    right->right = new TreeNode(3);

    Solution S;
    cout << S.hasPathSum(root, 6) << endl;
    return 0;
}
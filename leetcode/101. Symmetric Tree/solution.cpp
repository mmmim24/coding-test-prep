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
    bool mirror(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if (!left || !right)
            return false;
        return (left->val == right->val) && mirror(left->left, right->right) && mirror(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return mirror(root->left, root->right);
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

    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;
    cout << root->left->left->val << endl;
    cout << root->left->right->val << endl;
    cout << root->right->left->val << endl;
    cout << root->right->right->val << endl;
    Solution S;
    cout << endl
         << S.isSymmetric(root) << endl;
    return 0;
}
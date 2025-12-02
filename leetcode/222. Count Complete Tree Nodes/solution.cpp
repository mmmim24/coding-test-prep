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
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
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
    cout << S.countNodes(root) << endl;
    return 0;
}
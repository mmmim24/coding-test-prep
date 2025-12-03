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
    int ans = INT_MAX;
    int getMinimumDifference(TreeNode *root)
    {
        TreeNode *prev = nullptr;
        inorderTraversalDFS(root, prev);
        return ans;
    }
    void inorderTraversalDFS(TreeNode *node, TreeNode *&prev)
    {
        if (node == nullptr)
            return;
        inorderTraversalDFS(node->left, prev);
        if (prev != nullptr)
            ans = min(ans, node->val - prev->val);
        prev = node;
        inorderTraversalDFS(node->right, prev);
    }
};

int main()
{

    TreeNode *left = new TreeNode(0);
    TreeNode *right = new TreeNode(48);
    TreeNode *root = new TreeNode(24, left, right);
    right->left = new TreeNode(36);
    right->right = new TreeNode(49);

    Solution s;
    cout << s.getMinimumDifference(root) << endl;

    return 0;
}
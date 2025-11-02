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
    int maxPathSum(TreeNode *root)
    {
        int res = root->val;
        dfs(root, res);
        return res;
    }

private:
    int dfs(TreeNode *root, int &res)
    {
        if (!root)
        {
            return 0;
        }

        int leftMax = max(dfs(root->left, res), 0);
        int rightMax = max(dfs(root->right, res), 0);

        res = max(res, root->val + leftMax + rightMax);
        return root->val + max(leftMax, rightMax);
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

    cout << s.maxPathSum(root) << endl;

    return 0;
}
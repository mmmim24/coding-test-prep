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
    int minDiffInBST(TreeNode *root)
    {
        int prev = -1;
        dfs(root, prev);
        return ans;
    }

private:
    int ans = INT_MAX;
    void dfs(TreeNode *root, int &prev)
    {
        if (root == nullptr)
            return;
        dfs(root->left, prev);
        if (prev != -1)
            ans = min(ans, root->val - prev);
        prev = root->val;
        dfs(root->right, prev);
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
    cout << s.minDiffInBST(root) << endl;
    return 0;
}
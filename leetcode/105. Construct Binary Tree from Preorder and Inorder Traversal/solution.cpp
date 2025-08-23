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
    int pre_idx = 0;
    unordered_map<int, int> indices;

    TreeNode *dfs(vector<int> &preorder, int l, int r)
    {
        if (l > r)
            return nullptr;

        int root_val = preorder[pre_idx++];
        TreeNode *root = new TreeNode(root_val);
        int mid = indices[root_val];

        root->left = dfs(preorder, l, mid - 1);
        root->right = dfs(preorder, mid + 1, r);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
        {
            indices[inorder[i]] = i;
        }
        return dfs(preorder, 0, inorder.size() - 1);
    }
    void levelorderTraversal(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
};
int main()
{
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);
    s.levelorderTraversal(root);
    cout << endl;
    return 0;
}
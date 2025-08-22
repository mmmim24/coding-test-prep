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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode *> q;
        if (root != nullptr)
            q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            vector<int> tmp;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr)
                {
                    q.push(curr->left);
                    q.push(curr->right);
                    tmp.push_back(curr->val);
                }
            }
            if (!tmp.empty())
                ans.push_back(tmp);
        }
        return ans;
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
    vector<vector<int>> ans = s.levelOrder(root);
    for (auto level : ans)
    {
        for (auto node : level)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}
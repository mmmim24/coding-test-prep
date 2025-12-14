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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode *> level;
        level.push(root);
        level.push(nullptr);

        long long Sum = 0;
        int count = 0;
        double el = 0;

        while (!level.empty())
        {
            TreeNode *curr = level.front();
            level.pop();

            if (curr != nullptr)
            {
                Sum += curr->val;
                count++;
                if (curr->left != nullptr)
                    level.push(curr->left);
                if (curr->right != nullptr)
                    level.push(curr->right);
            }
            else
            {
                el = (Sum * 1.0) / count;
                ans.push_back(el);
                Sum = 0, count = 0, el = 0;

                if (!level.empty())
                    level.push(nullptr);
            }
        }
        return ans;
    }
};

int main()
{
    TreeNode *l = new TreeNode(2);
    l->left = new TreeNode(1);
    l->right = new TreeNode(3);
    TreeNode *r = new TreeNode(6);
    r->left = new TreeNode(5);
    r->right = new TreeNode(7);
    TreeNode *root = new TreeNode(4, l, r);
    Solution s;
    vector<double> ans = s.averageOfLevels(r);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *cur = root;

        while (cur)
        {
            if (p->val > cur->val && q->val > cur->val)
            {
                cur = cur->right;
            }
            else if (p->val < cur->val && q->val < cur->val)
            {
                cur = cur->left;
            }
            else
            {
                return cur;
            }
        }
        return nullptr;
    }
};
int main()
{
    TreeNode *root = new TreeNode(4);
    TreeNode *left = new TreeNode(2);
    left->left = new TreeNode(1);
    left->right = new TreeNode(3);
    TreeNode *right = new TreeNode(6);
    right->left = new TreeNode(5);
    right->right = new TreeNode(7);
    root->left = left, root->right = right;

    Solution s;
    TreeNode *ans = s.lowestCommonAncestor(root, left->left, left->right);
    cout << ans->val << endl; // 2

    return 0;
}
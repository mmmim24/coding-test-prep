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
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!subRoot)
        {
            return true;
        }
        if (!root)
        {
            return false;
        }
        if (root->val == subRoot->val)
        {
            if (isSameTree(root, subRoot))
            {
                return true;
            }
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (p && q && p->val == q->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return false;
    }
    void traverse(TreeNode *root)
    {
        TreeNode *curr = root;
        if (curr != nullptr)
            cout << curr->val << " ";
        if (curr->left != nullptr)
            traverse(curr->left);
        if (curr->right != nullptr)
            traverse(curr->right);
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

    s.traverse(root);
    cout << endl;
    s.traverse(right);
    cout << endl;

    s.isSubtree(root, right) ? cout << "Is Sub Tree\n" : cout << "Not Sub Tree\n";
    return 0;
}
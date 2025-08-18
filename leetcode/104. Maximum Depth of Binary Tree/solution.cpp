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
class SolutionDFS
{
public:
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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
    }
};
class SolutionBFS
{
public:
    void traverse(TreeNode *root)
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
    int maxDepth(TreeNode *root)
    {
        int depth = 0;
        queue<TreeNode *> q;
        if (root != nullptr)
            q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            depth++;
        }
        return depth;
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

    SolutionDFS s;

    s.traverse(root);
    cout << endl;

    cout << s.maxDepth(root) << "\n";

    SolutionBFS S;

    S.traverse(root);
    cout << endl;

    cout << S.maxDepth(root) << "\n";

    return 0;
}
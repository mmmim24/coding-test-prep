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
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
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
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            swap(curr->left, curr->right);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        return root;
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

    TreeNode *invert = s.invertTree(root);

    s.traverse(invert);
    cout << endl;

    SolutionBFS S;

    S.traverse(root);
    cout << endl;

    invert = S.invertTree(root);

    S.traverse(root);
    cout << endl;
    return 0;
}
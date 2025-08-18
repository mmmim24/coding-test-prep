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
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        TreeNode *invert = new TreeNode(root->val, root->left, root->right);
        swap(invert->left, invert->right);
        invertTree(invert->left);
        invertTree(invert->right);
        return invert;
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
class SolutionBFS
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        q1.push(p);
        q2.push(q);
        while (!q1.empty() && !q2.empty())
        {
            TreeNode *cur1 = q1.front();
            TreeNode *cur2 = q2.front();
            q1.pop();
            q2.pop();
            if (cur1 == nullptr && cur2 == nullptr)
                continue;
            if (cur1 == nullptr || cur2 == nullptr || (cur1->val != cur2->val))
                return false;

            q1.push(cur1->left);
            q1.push(cur1->right);

            q2.push(cur2->left);
            q2.push(cur2->right);
        }
        return true;
    }
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        TreeNode *invert = new TreeNode(root->val, root->left, root->right);
        queue<TreeNode *> q;
        q.push(invert);
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
        return invert;
    }
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

    TreeNode *invert = s.invertTree(root);

    s.traverse(root);
    cout << endl;
    s.traverse(invert);
    cout << endl;

    s.isSameTree(root, invert) ? cout << "Same Tree\n" : cout << "Not Same Tree\n";

    SolutionBFS S;

    invert = S.invertTree(invert);

    S.traverse(root);
    cout << endl;
    S.traverse(invert);
    cout << endl;

    S.isSameTree(root, invert) ? cout << "Same Tree\n" : cout << "Not Same Tree\n";

    return 0;
}
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
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> arr;
        dfs(root, arr);
        return arr[k - 1];
    }
    void dfs(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
            return;
        dfs(root->left, arr);
        arr.push_back(root->val);
        dfs(root->right, arr);
    }
};
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (!stk.empty() || curr != nullptr)
        {
            while (curr != nullptr)
            {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            k--;
            if (k == 0)
                return curr->val;
            curr = curr->right;
        }
        return -1;
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

    int k;
    cin >> k;
    Solution s;
    cout << s.kthSmallest(root, k);
    return 0;
}
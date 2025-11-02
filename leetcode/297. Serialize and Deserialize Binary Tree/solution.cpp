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

class Codec
{
private:
    void dfsSerialize(TreeNode *node, vector<string> &ans)
    {
        if (node == nullptr)
        {
            ans.push_back("null");
            return;
        }
        ans.push_back(to_string(node->val));
        dfsSerialize(node->left, ans);
        dfsSerialize(node->right, ans);
    }
    TreeNode *dfsDeserialize(vector<string> &ans, int &i)
    {
        if (ans[i] == "null")
        {
            i++;
            return nullptr;
        }
        TreeNode *node = new TreeNode(stoi(ans[i]));
        i++;
        node->left = dfsDeserialize(ans, i);
        node->right = dfsDeserialize(ans, i);
        return node;
    }

public:
    string serialize(TreeNode *root)
    {
        vector<string> ans;
        dfsSerialize(root, ans);
        ostringstream s;
        for (const auto &i : ans)
        {
            if (&i != &ans[0])
                s << ',';
            s << i;
        }
        return s.str();
    }

    TreeNode *deserialize(string data)
    {
        vector<string> ans;
        stringstream ss(data);
        string item;
        while (getline(ss, item, ','))
            ans.push_back(item);
        int i = 0;
        return dfsDeserialize(ans, i);
    }
};

int main()
{

    return 0;
}
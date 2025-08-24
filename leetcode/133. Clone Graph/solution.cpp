#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        unordered_map<Node *, Node *> mp;
        queue<Node *> q;
        mp[node] = new Node(node->val);
        q.push(node);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            for (Node *adjacent : curr->neighbors)
            {
                if (mp.find(adjacent) == mp.end())
                {
                    mp[adjacent] = new Node(adjacent->val);
                    q.push(adjacent);
                }
                mp[curr]->neighbors.push_back(mp[adjacent]);
            }
        }
        return mp[node];
    }
};
int main()
{
    int n;
    cin >> n;
    vector<Node *> nodes(n + 1, nullptr);
    for (int i = 1; i <= n; ++i)
    {
        nodes[i] = new Node(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            int nei;
            cin >> nei;
            nodes[i]->neighbors.push_back(nodes[nei]);
        }
    }
    Node *cloned = Solution().cloneGraph(nodes[1]);

    if (!cloned)
    {
        cout << 0 << '\n';
        return 0;
    }

    unordered_map<int, Node *> mp;
    queue<Node *> q;
    unordered_set<Node *> vis;
    q.push(cloned);
    vis.insert(cloned);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        mp[cur->val] = cur;
        for (Node *nei : cur->neighbors)
        {
            if (!vis.count(nei))
            {
                vis.insert(nei);
                q.push(nei);
            }
        }
    }

    vector<int> vals;
    vals.reserve(mp.size());
    for (auto &p : mp)
        vals.push_back(p.first);
    sort(vals.begin(), vals.end());

    cout << vals.size() << '\n';
    for (int v : vals)
    {
        Node *nd = mp[v];
        int k = nd->neighbors.size();
        cout << k;
        if (k > 0)
            cout << ' ';
        for (int i = 0; i < k; ++i)
        {
            cout << nd->neighbors[i]->val;
            if (i + 1 < k)
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
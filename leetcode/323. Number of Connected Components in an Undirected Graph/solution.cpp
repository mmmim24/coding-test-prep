#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void bfs(int node, vector<bool> &visit, vector<vector<int>> &adj)
    {
        queue<int> q;
        q.push(node);
        visit[node] = true;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < adj[curr].size(); i++)
            {
                if (!visit[adj[curr][i]])
                {
                    visit[adj[curr][i]] = true;
                    q.push(adj[curr][i]);
                }
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        for (int node = 0; node < n; node++)
        {
            if (!visit[node])
            {
                bfs(node, visit, adj);
                res++;
            }
        }
        return res;
    }
};
int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges(e);
    for (int i = 0; i < e; i++)
    {
        vector<int> edge(2);
        cin >> edge[0] >> edge[1];
        edges[i] = edge;
    }
    Solution sol;
    cout << sol.countComponents(v, edges) << endl;
    return 0;
}
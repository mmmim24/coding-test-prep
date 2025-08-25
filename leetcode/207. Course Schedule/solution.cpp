#include <bits/stdc++.h>
using namespace std;
class Solution
{

    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visited;

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        for (int i = 0; i < numCourses; i++)
        {
            preMap[i] = {};
        }
        for (int i = 0; i < prerequisites.size(); i++)
        {
            preMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(i))
            {
                return false;
            }
        }
        return true;
    }
    bool dfs(int course)
    {
        if (visited.count(course))
        {
            return false;
        }
        if (preMap[course].empty())
        {
            return true;
        }
        visited.insert(course);
        for (int i = 0; i < preMap[course].size(); i++)
        {
            if (!dfs(preMap[course][i]))
            {
                return false;
            }
        }
        visited.erase(course);
        preMap[course].clear();
        return true;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> prereq(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> dependecy(2);
        for (int j = 0; j < 2; j++)
        {
            cin >> dependecy[j];
        }
        prereq[i] = dependecy;
    }
    for (auto i : prereq)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
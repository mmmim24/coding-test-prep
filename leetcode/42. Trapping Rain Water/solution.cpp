#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0, n = height.size();
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, height[i]);
            left[i] = ans;
        }
        ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            ans = max(ans, height[i]);
            right[i] = ans;
        }
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (min(left[i], right[i]) - height[i]);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
        cin >> height[i];
    Solution s;
    cout << s.trap(height) << endl;
    return 0;
}
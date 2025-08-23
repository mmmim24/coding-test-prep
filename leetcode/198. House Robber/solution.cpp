#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int prev = 0, curr = 0;
        for (int num : nums)
        {
            int temp = max(num + prev, curr);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << Solution().rob(v) << endl;
    return 0;
}

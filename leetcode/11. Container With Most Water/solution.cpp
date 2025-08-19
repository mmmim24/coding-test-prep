#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int area = (j - i) * min(height[i], height[j]);
        while (i < j)
        {

            int width = (j - i);
            area = max(area, width * min(height[i], height[j]));
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return area;
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
    cout << s.maxArea(height) << endl;
    return 0;
}
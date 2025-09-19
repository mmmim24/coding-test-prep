#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> seen;
        bool ans = true;
        while (n != 1)
        {
            if (seen.find(n) != seen.end())
            {
                ans = false;
                break;
            }
            else
            {
                seen.insert(n);
                int temp = n;
                n = 0;
                while (temp)
                {
                    int d = temp % 10;
                    n += d * d;
                    temp /= 10;
                }
            }
        }
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.isHappy(n) << endl;
    return 0;
}
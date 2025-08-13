#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reverseBits(int n)
    {
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            int8_t bit = (n >> i) & 1;
            res += bit << (31 - i);
        }
        return res;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.reverseBits(n) << endl;
    return 0;
}
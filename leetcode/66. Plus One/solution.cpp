#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] > 8)
                digits[i] = 0;
            else
            {
                digits[i]++;
                break;
            }
        }
        if (digits[0] == 0)
        {
            digits.push_back(1);
            reverse(digits.begin(), digits.end());
            return digits;
        }
        return digits;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> digits(n);
    for (int i = 0; i < n; i++)
        cin >> digits[i];
    Solution S;
    vector<int> ans = S.plusOne(digits);
    for (int i = 0; i < ans.size(); i++)
        cout << digits[i] << " \n"[i == ans.size() - 1];
    return 0;
}
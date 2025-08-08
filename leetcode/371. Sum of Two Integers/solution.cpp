#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getSum(int a, int b)
    {
        int sum = a ^ b, carry = (a & b) << 1;
        while (carry != 0)
        {
            a = sum;
            b = carry;
            sum = a ^ b;
            carry = (a & b) << 1;
        }
        return sum;
    }
};
int main()
{
    int a, b;
    cin >> a >> b;
    Solution S;
    cout << S.getSum(a, b) << endl;
    return 0;
}
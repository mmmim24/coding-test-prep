#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (isalnum(s[i]) && isalnum(s[j]))
            {
                if (tolower(s[i]) != tolower(s[j]))
                    return false;
                else
                    i++, j--;
            }
            else
            {
                if (!isalnum(s[i]))
                    i++;
                if (!isalnum(s[j]))
                    j--;
            }
        }
        return true;
    }
};
int main()
{
    string s = "Was it a car or a cat I saw?";
    // cin >> s;
    Solution S;
    cout << S.isPalindrome(s) << endl;
    return 0;
}
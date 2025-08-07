#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                char t = st.top();
                if ((t == '{' && s[i] == '}') || (t == '[' && s[i] == ']') || (t == '(' && s[i] == ')'))
                {
                    st.pop();
                }
                else
                    st.push(s[i]);
            }
            // if (!st.empty())
            //     cout << st.top() << endl;
            // st.empty() ? cout << "empty\n" : cout << "not empty\n";
        }
        bool ans;
        st.empty() ? ans = true : ans = false;
        return ans;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution S;
    cout << S.isValid(s) << endl;
    return 0;
}
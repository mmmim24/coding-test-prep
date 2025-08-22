#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *result = new ListNode(0, head);
        ListNode *first = result;
        ListNode *second = head;
        while (n > 0)
        {
            second = second->next;
            n--;
        }
        while (second != nullptr)
        {
            first = first->next;
            second = second->next;
        }
        first->next = first->next->next;
        return result->next;
    }
};
int main()
{
    int n, x, m;
    cin >> n >> x;
    ListNode *head = new ListNode(x);
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        ListNode *temp = new ListNode(x);
        ListNode *t = head;
        while (t->next)
            t = t->next;
        t->next = temp;
    }
    cin >> m;
    ListNode *head2 = head;
    while (head2)
    {
        cout << head2->val << " ";
        head2 = head2->next;
    }
    cout << endl;
    Solution obj;
    head = obj.removeNthFromEnd(head, m);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}

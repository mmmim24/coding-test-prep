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
    void reorderList(ListNode *head)
    {
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *first = head, *second = slow->next;
        ListNode *prev = slow->next = nullptr;
        while (second != nullptr)
        {
            ListNode *temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        second = prev;
        while (second != nullptr)
        {
            ListNode *temp1 = first->next, *temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
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
    obj.reorderList(head);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}

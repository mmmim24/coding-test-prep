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
    void append(ListNode *&head, int value)
    {
        ListNode *newNode = new ListNode(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        ListNode *curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    void traverse(ListNode *head)
    {
        ListNode *curr = head;
        while (curr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(), *curr = ans;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int x = 0, y = 0;
            if (l1 != nullptr)
            {
                x += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                y += l2->val;
                l2 = l2->next;
            }

            carry += x + y;
            curr->next = new ListNode(carry % 10);

            curr = curr->next;

            carry = carry / 10;
        }
        return ans->next;
    }
};

int main()
{
    Solution s;
    ListNode *l1 = nullptr, *l2 = nullptr;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        s.append(l1, value);
    }

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        s.append(l2, value);
    }

    cout << "Original list1: ";
    s.traverse(l1);
    cout << "Original list2: ";
    s.traverse(l2);
    cout << "Appended list : ";
    s.traverse(s.addTwoNumbers(l1, l2));
    return 0;
}
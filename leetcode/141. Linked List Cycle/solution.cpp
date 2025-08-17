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
class SolutionSet
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> mp;
        ListNode *curr = head;
        while (curr)
        {
            if (mp.find(curr) == mp.end())
                return false;
            mp.insert(curr);
            curr = curr->next;
        }
        return true;
    }
};
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(5);

    list1->next->next->next = list2;

    Solution s;
    s.hasCycle(list1) ? cout << "Cycle\n" : cout << "No Cycle";
    return 0;
}
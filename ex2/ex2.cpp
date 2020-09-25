#include <bits/stdc++.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *Head = new ListNode(-1);
        ListNode *Current = Head;
        bool CF = false;
        while (l1 || l2 || CF)
        {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            Current = Current->next = new ListNode((a + b + CF) % 10);
            CF = (a + b + CF) / 10;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return Head->next;
    }
};
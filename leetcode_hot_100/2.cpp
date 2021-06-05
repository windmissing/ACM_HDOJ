/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0, nullptr);
        ListNode* last = head;
        int jinwei = 0;
        while(l1 || l2)
        {
            int a = 0, b = 0, c;
            if(l1)
            {
                a = l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                b = l2->val;
                l2 = l2->next;
            }
            c = a + b + jinwei;
            if (c > 9)
            {
                c = c % 10;
                jinwei = 1;
            }
            else
                jinwei = 0;
            last->next = new ListNode(c, nullptr);
            last = last->next;
        }
        if (jinwei > 0)
            last->next = new ListNode(1, nullptr);
        return head->next;
    }
};
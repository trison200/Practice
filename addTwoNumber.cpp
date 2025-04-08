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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        LLNode *tmp = new LLNode();
        LLNode *p = tmp;
        int r = 0;
        while (l0 != NULL || l1 != NULL || r)
        {
            int sum = r;
            if (l0 != NULL)
            {
                sum += l0->val;
                l0 = l0->next;
            }
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            r = sum / 10;
            p->next = new LLNode(sum % 10, NULL);
            p = p->next;
        }
        return tmp->next;
    }
};
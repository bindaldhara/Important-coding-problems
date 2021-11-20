Leetcode Question link: https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) 
            return l2;
        if (l2 == NULL) 
            return l1;
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* head = l2->val <= l1->val ? l2 : l1;
        ListNode* pre = NULL;
        while (p != NULL && q != NULL) {
            if (q->val <= p->val) {
                ListNode* node = q;
                q = q->next;
                node->next = p;
                if (pre != NULL) {
                    pre->next = node;
                }
                pre = node;
            } else {
                pre = p;
                p = p->next;
            }
        }
        if (q != NULL) {
            pre->next = q;
        }
        return head;
    }
};

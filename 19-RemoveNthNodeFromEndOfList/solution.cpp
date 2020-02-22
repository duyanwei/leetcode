/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * @brief trivial solution (two pointer)
 * 
 * @TIMECOMPLEXITY n
 * @SPACECOMPLEIXTY 2 * sizeof(ListNode)
 * 
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return head;
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* fast = dummy->next;
        ListNode* slow = dummy;
        
        while (n-- > 0 && fast != NULL) {
            fast = fast->next;
        }
        
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
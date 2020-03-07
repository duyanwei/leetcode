/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-03-01
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * @brief slow and fast pointer
 *
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL) {  // be careful with the stop criteria !!!
            fast = fast->next;
            if (fast != NULL) {  // be careful with this check !!!
                slow = slow->next;
                fast = fast->next;
                if (slow == fast) {
                    return true;
                }
            }
        }
        return false;
    }
};
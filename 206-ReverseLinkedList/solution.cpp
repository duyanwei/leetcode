/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-03-03
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // return reverseListRecursive(head);

        if (head == NULL) {
            return NULL;
        }

        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = cur->next;

        while (true) {
            cur->next = prev;
            prev = cur;
            cur = next;

            if (next == NULL) {
                break;
            }
            next = next->next;
        }

        return prev;
    }

private:
    // recursive
    ListNode* reverseListRecursive(ListNode* head) {
        ListNode* cur = NULL;
        reverseListRecursive(head, &cur);
        return cur;
    }

    void reverseListRecursive(ListNode* head, ListNode** cur) const {
        if (head == NULL) {
            return;
        }

        ListNode* old = head;
        head = head->next;
        old->next = *cur;
        *cur = old;
        return reverseListRecursive(head, cur);
    }
};
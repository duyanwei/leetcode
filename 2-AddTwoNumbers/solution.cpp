/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-01-29
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <vector>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        const int sum1 = listToValue(l1);
        const int sum2 = listToValue(l2);
        return valueToList(sum1 + sum2);
    }

private:
    int listToValue(const ListNode* l) const {
        if (l == NULL) {
            return 0;
        }
        return l->val + 10 * listToValue(l->next);
    }

    ListNode* valueToList(const int value) const {
        ListNode* list;
        ListNode* head;
        int v = value;
        while (true) {
            ListNode* l = new ListNode(v % 10);
            if (v == value) {
                list = l;
                head = list;
            } else {
                list->next = l;
                list = list->next;
            }
            v /= 10;

            if (v == 0) {
                break;
            }
        }
        return head;
    }
};

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newlist = new ListNode(-1);
        ListNode* cur = newlist;

        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            const int v1 = l1 == NULL ? 0 : l1->val;
            const int v2 = l2 == NULL ? 0 : l2->val;
            const int sum = v1 + v2 + carry;
            carry = sum / 10;
            ListNode* l = new ListNode(sum % 10);
            cur->next = l;
            cur = cur->next;

            l1 = l1 == NULL ? NULL : l1->next;
            l2 = l2 == NULL ? NULL : l2->next;
        }

        if (carry > 0) {
            ListNode* l = new ListNode(carry);
            cur->next = l;
        }
        cur = newlist->next;
        delete newlist;
        return cur;
    }
};

int main() { return 0; }
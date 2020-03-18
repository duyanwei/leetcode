/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-03-09
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
 * @brief
 *
 * @TIMECOMPLEXITY O(n)
 * @SPACECOMPLEXITY O(n)
 *
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<int> values;

        ListNode* cur = head;
        while (cur != NULL) {
            values.push_back(cur->val);
            cur = cur->next;
        }

        cur = head;
        for (int j = values.size() - 1; cur != NULL && j >= 0;
             cur = cur->next, j--) {
            if (cur->val != values.at(j)) {
                return false;
            }
        }
        return true;
    }
};

/**
 * @brief reverse the second half list node
 *
 * @SPACECOMPLEXITY O(1)
 * @TIMECOMPLEXITY O(n)
 */
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* cur = head;
        ListNode* fast = cur;

        while (fast != NULL && fast->next != NULL) {
            cur = cur->next;
            fast = fast->next->next;
        }

        ListNode* reverse = reverseNode(cur);
        cur = head;
        while (cur != NULL && reverse != NULL) {
            std::cout << reverse->val << std::endl;
            if (cur->val != reverse->val) {
                return false;
            }
            cur = cur->next;
            reverse = reverse->next;
        }
        return true;
    }

    ListNode* reverseNode(ListNode* node) const {
        ListNode* prev = NULL;
        ListNode* cur = node;
        while (cur != NULL) {
            ListNode* fast = cur->next;
            cur->next = prev;
            prev = cur;
            cur = fast;
        }
        return prev;
    }
};

int main() {

    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(4);
    cur = cur->next;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(1);
    cur = cur->next;

    Solution2 s;
    std::cout << s.isPalindrome(head) << std::endl;

    return 0;
}

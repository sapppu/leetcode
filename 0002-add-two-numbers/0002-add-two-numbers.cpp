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
        ListNode dummy;
        ListNode* tail = &dummy;
        int carry = 0;

        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* rest = l1 ? l1 : l2;
        while (rest && carry) {
            int sum = rest->val + carry;
            rest->val = sum % 10;
            carry = sum / 10;
            tail->next = rest;
            tail = rest;
            rest = rest->next;
        }

        if (rest)       tail->next = rest;
        else if (carry) tail->next = new ListNode(1); // carry ≤ 1 always

        return dummy.next;
    }
};
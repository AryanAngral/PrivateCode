/*
Problem: Palindrome Linked List
Link: https://leetcode.com/problems/palindrome-linked-list/

Given a singly linked list, determine if it is a palindrome.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* prev = nullptr;
    while (slow) {
        ListNode* next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }
    while (prev) {
        if (head->val != prev->val) return false;
        head = head->next;
        prev = prev->next;
    }
    return true;
}
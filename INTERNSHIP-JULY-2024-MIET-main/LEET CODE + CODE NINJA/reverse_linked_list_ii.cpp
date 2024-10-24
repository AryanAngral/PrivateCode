/*
Problem: Reverse Linked List II
Link: https://leetcode.com/problems/reverse-linked-list-ii/

Reverse a linked list from position m to n. Do it in one-pass.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head) return nullptr;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    for (int i = 1; i < m; ++i) {
        prev = prev->next;
    }
    ListNode* current = prev->next;
    for (int i = 0; i < n - m; ++i) {
        ListNode* next = current->next;
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    return dummy->next;
}
/*
Problem: Remove Linked List Elements
Link: https://leetcode.com/problems/remove-linked-list-elements/

Remove all elements from a linked list of integers that have value val.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* current = dummy;
    while (current->next) {
        if (current->next->val == val) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    return dummy->next;
}
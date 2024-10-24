/*
Problem: Middle of the Linked List
Link: https://leetcode.com/problems/middle-of-the-linked-list/

Given a non-empty, singly linked list with head node head, return a middle node of linked list.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
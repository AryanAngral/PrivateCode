
/*
Problem: Remove All Nodes With Value K
Link: https://www.codingninjas.com/codestudio/problems/remove-all-nodes-with-value-k_1262145

Remove all the nodes of the linked list that have Node.val == k.
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* current = &dummy;
    while (current->next) {
        if (current->next->val == val) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    return dummy.next;
}

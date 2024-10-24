
/*
Problem: Cycle Detection in a Singly Linked List
Link: https://www.codingninjas.com/codestudio/problem-details/cycle-detection-in-a-singly-linked-list_628974

Detect if a linked list has a cycle in it.
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

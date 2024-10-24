
/*
Problem: Middle of the Linked List
Link: https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250

Given the head of a singly linked list, return the middle node of the linked list.
*/
#include<bits/stdc++.h>
using namespace std;
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


/*
Problem: Delete Node in a Linked List
Link: https://www.codingninjas.com/codestudio/problems/delete-node-in-ll_5881

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

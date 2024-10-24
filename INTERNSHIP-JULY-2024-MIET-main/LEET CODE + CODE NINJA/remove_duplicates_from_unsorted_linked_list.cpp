
/*
Problem: Remove Duplicates from Unsorted Linked List
Link: https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331

Write a function to remove duplicates from an unsorted linked list.
*/
#include<bits/stdc++.h>

#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeDuplicates(ListNode* head) {
    if (!head) return nullptr;
    unordered_set<int> seen;
    ListNode* current = head;
    seen.insert(current->val);
    while (current->next) {
        if (seen.count(current->next->val)) {
            current->next = current->next->next;
        } else {
            seen.insert(current->next->val);
            current = current->next;
        }
    }
    return head;
}

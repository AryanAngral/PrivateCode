
/*
Problem: Palindrome Linked List
Link: https://www.codingninjas.com/codestudio/problems/palindrom-linked-list_799352?leftPanelTab=0

Given the head of a singly linked list, return true if it is a palindrome.
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = reverse(slow);
    fast = head;
    while (slow) {
        if (slow->val != fast->val) return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

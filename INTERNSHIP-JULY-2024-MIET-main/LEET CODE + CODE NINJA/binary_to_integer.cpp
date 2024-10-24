
/*
Problem: Convert Binary Number in a Linked List to Integer
Link: https://www.codingninjas.com/codestudio/problems/binary-to-integer_2421938

Given head which is a reference node to a singly-linked list, return the decimal value of the number in the linked list.
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int getDecimalValue(ListNode* head) {
    int num = 0;
    while (head) {
        num = (num << 1) | head->val;
        head = head->next;
    }
    return num;
}

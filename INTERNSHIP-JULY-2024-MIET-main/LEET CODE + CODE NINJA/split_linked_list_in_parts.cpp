/*
Problem: Split Linked List in Parts
Link: https://leetcode.com/problems/split-linked-list-in-parts/

Split a linked list into k consecutive linked list parts.
*/

#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

vector<ListNode*> splitListToParts(ListNode* root, int k) {
    int len = 0;
    ListNode* current = root;
    while (current) {
        len++;
        current = current->next;
    }
    
    int n = len / k, r = len % k;
    vector<ListNode*> parts(k, nullptr);
    current = root;
    for (int i = 0; i < k && current; ++i) {
        parts[i] = current;
        for (int j = 1; j < n + (i < r); ++j) {
            current = current->next;
        }
        ListNode* next = current->next;
        current->next = nullptr;
        current = next;
    }
    return parts;
}
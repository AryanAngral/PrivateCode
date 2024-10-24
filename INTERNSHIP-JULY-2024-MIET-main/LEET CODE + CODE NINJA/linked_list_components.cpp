/*
Problem: Linked List Components
Link: https://leetcode.com/problems/linked-list-components/

Given the head of a linked list containing unique integers, and an array G of integers, return the number of connected components in G.
*/

#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int numComponents(ListNode* head, vector<int>& G) {
    unordered_set<int> Gset(G.begin(), G.end());
    int count = 0;
    while (head) {
        if (Gset.count(head->val) && (!head->next || !Gset.count(head->next->val))) {
            count++;
        }
        head = head->next;
    }
    return count;
}
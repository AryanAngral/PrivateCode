/*
Problem: Design Linked List
Link: https://leetcode.com/problems/design-linked-list/

Design your implementation of the linked list.
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class MyLinkedList {
public:
    MyLinkedList() : head(nullptr), size(0) {}
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) {
            addAtHead(val);
        } else {
            ListNode* newNode = new ListNode(val);
            ListNode* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        } else {
            ListNode* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        size--;
    }

private:
    ListNode* head;
    int size;
};
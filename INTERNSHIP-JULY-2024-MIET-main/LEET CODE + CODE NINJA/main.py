import os

# Define the directory where you want to save the files
directory = r"C:\vs code\placements\LEET CODE + CODE NINJA"

# Define the problems and their corresponding code
array_problems = {
    "path_with_maximum_probability.cpp": """
/*
Problem: Path with Maximum Probability
Link: https://leetcode.com/problems/path-with-maximum-probability/

You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
*/

#include <vector>
#include <queue>
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<vector<pair<int, double>>> graph(n);
    for (int i = 0; i < edges.size(); ++i) {
        graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
        graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
    }
    
    priority_queue<pair<double, int>> pq;
    pq.emplace(1.0, start);
    vector<double> probabilities(n, 0.0);
    probabilities[start] = 1.0;
    
    while (!pq.empty()) {
        auto [prob, node] = pq.top(); pq.pop();
        if (node == end) return prob;
        for (auto [neighbor, edgeProb] : graph[node]) {
            double newProb = prob * edgeProb;
            if (newProb > probabilities[neighbor]) {
                probabilities[neighbor] = newProb;
                pq.emplace(newProb, neighbor);
            }
        }
    }
    
    return 0.0;
}
""",
    "linked_list_cycle.cpp": """
/*
Problem: Linked List Cycle
Link: https://leetcode.com/problems/linked-list-cycle/

Given a linked list, determine if it has a cycle in it.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;
    ListNode *slow = head, *fast = head->next;
    while (slow != fast) {
        if (!fast || !fast->next) return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}
""",
    "reverse_linked_list.cpp": """
/*
Problem: Reverse Linked List
Link: https://leetcode.com/problems/reverse-linked-list/

Reverse a singly linked list.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
""",
    "palindrome_linked_list.cpp": """
/*
Problem: Palindrome Linked List
Link: https://leetcode.com/problems/palindrome-linked-list/

Given a singly linked list, determine if it is a palindrome.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* prev = nullptr;
    while (slow) {
        ListNode* next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }
    while (prev) {
        if (head->val != prev->val) return false;
        head = head->next;
        prev = prev->next;
    }
    return true;
}
""",
    "linked_list_components.cpp": """
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
""",
    "design_linked_list.cpp": """
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
""",
    "reverse_linked_list_ii.cpp": """
/*
Problem: Reverse Linked List II
Link: https://leetcode.com/problems/reverse-linked-list-ii/

Reverse a linked list from position m to n. Do it in one-pass.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head) return nullptr;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    for (int i = 1; i < m; ++i) {
        prev = prev->next;
    }
    ListNode* current = prev->next;
    for (int i = 0; i < n - m; ++i) {
        ListNode* next = current->next;
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    return dummy->next;
}
""",
    "linked_list_cycle_ii.cpp": """
/*
Problem: Linked List Cycle II
Link: https://leetcode.com/problems/linked-list-cycle-ii/

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head) {
    if (!head || !head->next) return nullptr;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
""",
    "remove_linked_list_elements.cpp": """
/*
Problem: Remove Linked List Elements
Link: https://leetcode.com/problems/remove-linked-list-elements/

Remove all elements from a linked list of integers that have value val.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* current = dummy;
    while (current->next) {
        if (current->next->val == val) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    return dummy->next;
}
""",
    "odd_even_linked_list.cpp": """
/*
Problem: Odd Even Linked List
Link: https://leetcode.com/problems/odd-even-linked-list/

Given a singly linked list, group all odd nodes together followed by the even nodes.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (!head) return nullptr;
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
""",
    "split_linked_list_in_parts.cpp": """
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
""",
    "middle_of_the_linked_list.cpp": """
/*
Problem: Middle of the Linked List
Link: https://leetcode.com/problems/middle-of-the-linked-list/

Given a non-empty, singly linked list with head node head, return a middle node of linked list.
*/

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
"""
}

# Create directory if it doesn't exist
os.makedirs(directory, exist_ok=True)

# Write each problem to a file
for filename, code in array_problems.items():
    file_path = os.path.join(directory, filename)
    with open(file_path, "w") as file:
        file.write(code.strip())

print("Files have been created successfully.")

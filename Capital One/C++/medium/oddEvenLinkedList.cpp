#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // If the list is empty or has only one node
        if (!head || !head->next) return head;

        ListNode* odd = head;           // Pointer to the last node in the odd indexed list
        ListNode* even = head->next;    // Pointer to the last node in the even indexed list
        ListNode* evenHead = even;      // Store the head of the even list

        // Iterate through the list and rearrange nodes
        while (even && even->next) {
            odd->next = even->next;     // Link odd nodes
            odd = odd->next;            // Move to the next odd node
            even->next = odd->next;     // Link even nodes
            even = even->next;          // Move to the next even node
        }

        // Connect the end of the odd list to the head of the even list
        odd->next = evenHead;
        return head;                    // Return the head of the modified list
    }
};

// Helper function to create a linked list from a vector of integers
ListNode* createLinkedList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        head = head->next;
        if (head) std::cout << " -> ";
    }
    std::cout << std::endl;
}

// Test cases
int main() {
    Solution solution;

    // Test case 1
    std::vector<int> values1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createLinkedList(values1);
    ListNode* result1 = solution.oddEvenList(head1);
    printLinkedList(result1); // Output: 1 -> 3 -> 5 -> 2 -> 4

    // Test case 2
    std::vector<int> values2 = {2, 1, 3, 5, 6, 4, 7};
    ListNode* head2 = createLinkedList(values2);
    ListNode* result2 = solution.oddEvenList(head2);
    printLinkedList(result2); // Output: 2 -> 3 -> 6 -> 7 -> 1 -> 5 -> 4

    return 0;
}

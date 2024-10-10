#include <iostream>
#include <vector> 

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node that points to the head of the list
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy; // Pointer to traverse the list
        
        // Traverse the list
        while (current->next != nullptr) {
            if (current->next->val == val) {
                // If the next node needs to be removed, skip it
                current->next = current->next->next;
            } else {
                // Otherwise, move to the next node
                current = current->next;
            }
        }
        
        // Return the new head of the modified list
        return dummy.next;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode; // First node becomes head
            tail = head;
        } else {
            tail->next = newNode; // Link the new node
            tail = newNode; // Move tail to the new node
        }
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the solution
int main() {
    Solution solution;

    // Example 1
    vector<int> values1 = {1, 2, 6, 3, 4, 5, 6};
    ListNode* head1 = createLinkedList(values1);
    head1 = solution.removeElements(head1, 6);
    cout << "Example 1 Output: ";
    printLinkedList(head1); // Output: 1 2 3 4 5

    // Example 2
    ListNode* head2 = nullptr; // Empty list
    head2 = solution.removeElements(head2, 1);
    cout << "Example 2 Output: ";
    printLinkedList(head2); // Output: (empty)

    // Example 3
    vector<int> values3 = {7, 7, 7, 7};
    ListNode* head3 = createLinkedList(values3);
    head3 = solution.removeElements(head3, 7);
    cout << "Example 3 Output: ";
    printLinkedList(head3); // Output: (empty)

    return 0;
}

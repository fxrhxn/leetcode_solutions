#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy head for the result linked list
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;  // Pointer to construct the new list
        int carry = 0;  // Initialize carry to 0

        // Loop until both lists are empty and no carry is left
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;  // Start with the carry from the previous iteration

            // Add the value of l1 if it exists
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;  // Move to the next node in l1
            }

            // Add the value of l2 if it exists
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;  // Move to the next node in l2
            }

            carry = sum / 10;  // Calculate the carry for the next iteration
            current->next = new ListNode(sum % 10);  // Create a new node with the digit value
            current = current->next;  // Move to the next node in the result list
        }

        return dummyHead->next;  // Return the next of the dummy head, which is the actual head of the result
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

// Main function to test the code
int main() {
    Solution solution;

    // Create the first linked list: 2 -> 4 -> 3 (represents the number 342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Create the second linked list: 5 -> 6 -> 4 (represents the number 465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Add the two numbers
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result: expected output: 7 -> 0 -> 8 (represents the number 807)
    std::cout << "Result: ";
    printList(result);

    // Clean up memory (not shown: you would want to free the nodes)

    return 0;
}

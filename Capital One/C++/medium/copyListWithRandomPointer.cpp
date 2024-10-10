#include <iostream>
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int value) : val(value), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Create a mapping from original nodes to their copies
        std::unordered_map<Node*, Node*> oldToNew;

        // First pass: create all nodes and store them in the map
        Node* current = head;
        while (current) {
            oldToNew[current] = new Node(current->val);
            current = current->next;
        }

        // Second pass: assign next and random pointers
        current = head;
        while (current) {
            Node* copy = oldToNew[current];
            copy->next = oldToNew[current->next];
            copy->random = oldToNew[current->random];
            current = current->next;
        }

        // Return the head of the copied linked list
        return oldToNew[head];
    }
};

// Function to print the linked list (for testing purposes)
void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << "Value: " << current->val;
        if (current->random) {
            std::cout << ", Random: " << current->random->val;
        } else {
            std::cout << ", Random: null";
        }
        std::cout << std::endl;
        current = current->next;
    }
}

// Main function to test the solution
int main() {
    Solution solution;

    // Create a test case: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* head = new Node(7);
    Node* node1 = new Node(13);
    Node* node2 = new Node(11);
    Node* node3 = new Node(10);
    Node* node4 = new Node(1);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    node1->random = head;    // random pointer to node with value 7
    node2->random = node3;   // random pointer to node with value 10
    node3->random = node2;   // random pointer to node with value 11
    node4->random = head;     // random pointer to node with value 7

    // Print original list
    std::cout << "Original list:" << std::endl;
    printList(head);

    // Copy the list
    Node* copiedList = solution.copyRandomList(head);

    // Print copied list
    std::cout << "\nCopied list:" << std::endl;
    printList(copiedList);

    // Clean up memory (not shown: you would want to free the nodes)

    return 0;
}

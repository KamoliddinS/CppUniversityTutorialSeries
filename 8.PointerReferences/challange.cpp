#include <iostream>

int main() {
    int* numberArray = new int[5];

    for (int i = 0; i < 5; ++i) {
        numberArray[i] = i * i;
    }
    // Accordingt to my business logic i use this array and print out the values
    for (int i = 0; i < 5; ++i) {
        std::cout << "numberArray[" << i << "] = " << numberArray[i] << std::endl;
    }


    // Business logic is done
    std::cout << "Program completed." << std::endl;

    return 0;
}
#include <iostream>

using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {} // this is a constructor for Node

};

// Function to add a node to the end of the list
void append(Node** head, int newData) {
    Node* newNode = new Node(newData);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to remove a node by value
bool remove(Node** head, int valueToRemove) {
    if (*head == nullptr) return false;
    Node* temp = *head;
    Node* prev = nullptr;
    
    // If head node itself holds the key to be deleted
    if (temp != nullptr && temp->data == valueToRemove) {
        *head = temp->next; // Changed head
        delete temp;        // Free old head
        return true;
    }
    
    // Search for the key to be deleted, keep track of the previous node
    while (temp != nullptr && temp->data != valueToRemove) {
        prev = temp;
        temp = temp->next;
    }
    
    // If key was not present in linked list
    if (temp == nullptr) return false;
    
    // Unlink the node from linked list
    prev->next = temp->next;
    delete temp; // Free memory
    
    return true;
}

// Function to print the linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Main Function
int main() {
    Node* head = nullptr;
    
    // Node node 
    // node.data = 1;
    // node.next = nullptr;
    
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    
    cout << "Linked List: ";
    printList(head);
    
    remove(&head, 3);
    
    cout << "After removing 3: ";
    printList(head);
    
    // Clean up memory
    while (remove(&head, head->data)) {}
    
    return 0;
}






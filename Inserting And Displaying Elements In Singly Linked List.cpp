#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int data;
    unique_ptr<Node> next; // Use unique_ptr for automatic memory management
};

class LinkedList {
private:
    unique_ptr<Node> head; // Smart pointer for the head of the list

public:
    // Function to insert data into the linked list
    void insert(int data) {
        auto newNode = make_unique<Node>(); // Create a new node
        newNode->data = data;
        newNode->next = move(head); // Move the current head to the new node's next
        head = move(newNode); // Update head to the new node
    }

    // Function to display the linked list
    void display() const {
        Node* temp = head.get(); // Use raw pointer for traversal
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next.get(); // Get the raw pointer of next node
        }
    }
};

int main() {
    LinkedList list; // Create a linked list instance
    int n, j;

    cout << "Enter the total number of elements you want to insert in the linked list: ";  
    cin >> n;
    cout << "Enter the elements: \n";
    for (int i = 0; i < n; i++) {
        cin >> j;
        list.insert(j); // Insert each element into the list
    }

    cout << "\nDisplaying the linked list: ";
    list.display(); // Display the linked list

    return 0; // Automatically cleans up memory with unique_ptr
}

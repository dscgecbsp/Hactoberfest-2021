#include <iostream>
using namespace std;
 
struct Node {
    int data;
    struct Node* next;
};
 
void push(struct Node** head_ref, int new_data);
 
bool isPresent(struct Node* head, int data);
 
/* Function to get union of two
linked lists head1 and head2 */
struct Node* getUnion(
    struct Node* head1,
    struct Node* head2)
{
    struct Node* result = NULL;
    struct Node *t1 = head1, *t2 = head2;

    while (t1 != NULL) {
        push(&result, t1->data);
        t1 = t1->next;
    }
 
    
    while (t2 != NULL) {
        if (!isPresent(result, t2->data))
            push(&result, t2->data);
        t2 = t2->next;
    }
    return result;
}
 
/* Function to get intersection of
two linked lists head1 and head2 */
struct Node* getIntersection(struct Node* head1,
                            struct Node* head2)
{
    struct Node* result = NULL;
    struct Node* t1 = head1;
 
    // Traverse list1 and search each element of it in
    // list2. If the element is present in list 2, then
    // insert the element to result
    while (t1 != NULL) {
        if (isPresent(head2, t1->data))
            push(&result, t1->data);
        t1 = t1->next;
    }
    return result;
}
 
/* A utility function to insert a
node at the beginning of a linked list*/
void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node
        = (struct Node*)malloc(
            sizeof(struct Node));
 
    new_node->data = new_data;
 
    new_node->next = (*head_ref);
 
    (*head_ref) = new_node;
}
 
void printList(struct Node* node)
{
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}
 
/* A utility function that returns true if data is
present in linked list else return false */
bool isPresent(struct Node* head, int data)
{
    struct Node* t = head;
    while (t != NULL) {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}
 
int main()
{
   
    /* Start with the empty list */
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* intersecn = NULL;
    struct Node* unin = NULL;
 
    /*create a linked list1 */
    push(&head1, 25);
    push(&head1, 14);
    push(&head1, 5);
    push(&head1, 10);
 
    /*create a linked list2 */
    push(&head2, 10);
    push(&head2, 2);
    push(&head2, 14);
    push(&head2, 8);
    intersecn = getIntersection(head1, head2);
    unin = getUnion(head1, head2);
    cout << "\n First list is " << endl;
    printList(head1);
    cout << "\n Second list is " << endl;
    printList(head2);
    cout << "\n Intersection list is " << endl;
    printList(intersecn);
    cout << "\n Union list is " << endl;
    printList(unin);
    return 0;
}

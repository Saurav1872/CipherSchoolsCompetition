#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
Node *getMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *merge(Node *left, Node *right)
{
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    Node *start = new Node(-1);
    Node *temp = start;
    while (left != NULL && right != NULL) {

        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while (left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    start = start->next;
    return start;
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *middle = getMiddle(head);
    Node *left = head;
    Node *right = middle->next;
    middle->next = NULL;
    left = mergeSort(left);
    right = mergeSort(right);
    Node *ans = merge(left, right);
    return ans;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    Node *head = NULL;

    push(&head, 3);
    push(&head, 4);
    push(&head, 2);
    push(&head, 5);
    push(&head, 1);

    cout << "Linked list before sorting: " << endl;
    printList(head);

    Node *sortedList = mergeSort(head);

    cout << "Linked list after sorting: " << endl;
    printList(sortedList);

    return 0;
}
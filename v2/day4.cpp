#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* reverseKGroup(Node* head, int k) {
        int size = 0;
        Node* ptr = head;\
        while(ptr) {
            size++;
            ptr = ptr->next;
        }
        if(size < k) {
            return head;
        }
        Node* prev = NULL;
        Node* temp = head;
        int i = 0;

        while(temp != NULL && i < k ) {
            Node* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            i++;
        }
        if(temp != NULL) {
            head->next = reverseKGroup(temp,k);
        }
        return prev;
    }

void append(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}
void printLinkedList(Node *head)
{
    Node *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
int main()
{
    cout << "Input: " << endl;
    int n;
    cin >> n;

    int val;
    Node *head = nullptr;
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        append(head, val);
    }
    int k;
    cin >> k;
    cout << "Output: " << endl;
    head = reverseKGroup(head, k);
    printLinkedList(head);
    return 0;
}

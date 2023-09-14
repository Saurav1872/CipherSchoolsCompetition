#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

Node *oddEvenList(Node *head)
{
    if (!head)
        return NULL;
    if (!head->next)
        return head;

    Node *odd = head, *even = head->next;
    Node *node = head->next;

    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = node;
    return head;
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
    cout << "Output: " << endl;
    oddEvenList(head);
    printLinkedList(head);
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

Node *rotate(Node *head, int k)
{
    if (!head || !head->next || !k)
    {
        return head;
    }
    Node *curr = head;
    int len = 1;
    while (curr->next)
    {
        curr = curr->next;
        ++len;
    }
    curr->next = head;
    k = k % len;
    k = len - k;
    while (k--)
    {
        curr = curr->next;
    }
    head = curr->next;
    curr->next = NULL;

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
    int k;
    cin >> k;
    cout << "Output: " << endl;
    head = rotate(head, k);
    printLinkedList(head);
    return 0;
}

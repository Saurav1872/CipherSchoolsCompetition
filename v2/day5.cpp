#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

Node *merge(Node *head1, Node *head2)
{
    Node *head = new Node(-1);
    Node *ptr = head;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->val < head2->val)
        {
            ptr->next = head1;
            head1 = head1->next;
        }
        else
        {
            ptr->next = head2;
            head2 = head2->next;
        }
        ptr = ptr->next;
    }
    ptr->next = (head1 != NULL) ? head1 : head2;
    return head->next;
}

Node *divideLists(vector<Node *> &lists, int start, int end)
{
    if (start > end)
        return NULL;
    if (start == end)
        return lists[start];

    int mid = start + (end - start) / 2;
    Node *left = divideLists(lists, start, mid);
    Node *right = divideLists(lists, mid + 1, end);
    return merge(left, right);
}

Node *mergeKLists(vector<Node *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    return divideLists(lists, 0, lists.size() - 1);
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
    int n, m;
    cin >> n;

    int val;
    Node *head;
    vector<Node *> lists;
    for(int i = 0; i < n; ++i) {
        cin >> m;
        head = nullptr;
        for (int j = 0; j < m; ++j)
        {
            cin >> val;
            append(head, val);
        }
        lists.push_back(head);
    }
    cout << "Output: " << endl;
    printLinkedList(mergeKLists(lists));
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};
int twinPairSum(Node *head) {
    int res = 0;
    vector<int> arr;
    while (head->next != NULL) {
        arr.push_back(head->val);
        head = head->next;
    }
    arr.push_back(head->val);
    for (int i = 0; i < (int)arr.size() / 2; i++) {
        res = max(res, arr[i] + arr[(int)arr.size() - i - 1]);
    }
    return res;
}
void append(Node *&head, int val) {
    Node *newNode = new Node(val);
    if (!head) {
        head = newNode;
    }
    else {
        Node *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void printLinkedList(Node *head)
{
    Node *current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    cout << "Input: " << endl;
    int n;
    cin >> n;

    Node *head = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        append(head, val);
    }
    cout << "Output: " << endl;
    cout << twinPairSum(head) << endl;
    return 0;
}

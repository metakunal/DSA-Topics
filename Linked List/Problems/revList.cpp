#include <bits/stdc++.h>
using namespace std;

//Reverse a linked list in an iterative manner.
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
//------------------------NAIVE-------------------------
Node *revList(Node *head)
{
    vector<int> arr;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        arr.push_back(curr->data);
    }
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        curr->data = arr.back();
        arr.pop_back();
    }
    return head;
}
//----------------------EFFICIENT------------------------
Node *revListEff(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    printlist(head);
    cout << "The reversed Linked List is : ";
    head = revList(head);
    printlist(head);
    cout << "Reversed Again :" << endl;
    head = revListEff(head);
    printlist(head);
    return 0;
}

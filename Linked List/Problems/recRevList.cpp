#include <bits/stdc++.h>
using namespace std;

//Reverse a linked list in a recursive manner.
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
//------------------------METHOD-1-------------------------
Node *recRevList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *rest_head = recRevList(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
}
//----------------------METHOD-2------------------------
Node *recRevListEff(Node *curr, Node *prev)
{
    if (curr == NULL)
        return prev;
    Node *next = curr->next;
    curr->next = prev;
    return recRevListEff(next, curr);
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
    head = recRevList(head);
    printlist(head);
    cout << "Reversed Again :" << endl;
    head = recRevListEff(head, NULL);
    printlist(head);
    return 0;
}

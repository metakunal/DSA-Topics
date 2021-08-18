#include <bits/stdc++.h>
using namespace std;

//Program to insert at the end of DLL(Doubly Linked List)
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};
Node *insertEnd(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    temp->prev = curr;
    curr->next = temp;
    return head;
}
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

int main()
{
    // Node *head = NULL;
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    head = insertEnd(head, 5);
    printlist(head);
    return 0;
}

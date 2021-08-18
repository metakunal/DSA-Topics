#include <bits/stdc++.h>
using namespace std;

//Program to delete the head of CLL.
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
//---------------NAIVE SOLUTON--------------
Node *delHead(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while (curr->next != head)
        curr = curr->next;
    curr->next = head->next;
    delete head;
    return (curr->next);
}
//----------------EFFICIENT SOLUTION-----------------
Node *delHeadEff(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    head->data = head->next->data;
    Node *temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}
void printlist(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    for (Node *p = head->next; p != head; p = p->next)
        cout << p->data << " ";
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;
    head = delHead(head);
    head = delHeadEff(head);
    printlist(head);
    return 0;
}

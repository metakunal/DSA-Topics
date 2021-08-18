#include <bits/stdc++.h>
using namespace std;

//Program to insert at the beginning of CLL.
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
Node *insertBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
        temp->next = temp;
    else
    {
        Node *curr = head;
        while (curr->next != head)
            curr = curr->next;
        curr->next = temp;
        temp->next = head;
    }
    return temp;
}
//----------------EFFICIENT SOLUTION-----------------
Node *insertBeginEff(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
        int t = head->data;
        head->data = temp->data;
        temp->data = t;
        return head;
    }
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
    head = insertBegin(head, 5);
    head = insertBeginEff(head, 10);
    printlist(head);
    return 0;
}

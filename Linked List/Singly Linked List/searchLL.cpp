#include <bits/stdc++.h>
using namespace std;

//Program to search a key in the Linked List(Iterative and Recursive Solutions)
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

int searchLL(Node *head, int x)
{
    int pos = 1;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == x)
            return pos;
        else
        {
            pos++;
            curr = curr->next;
        }
    }
    return -1;
}
int recSearchLL(Node *head, int x)
{
    if (head == NULL)
        return -1;
    if (head->data == x)
        return 1;
    else
    {
        int res = recSearchLL(head->next, x);
        if (res == -1)
            return -1;
        else
            return (res + 1);
    }
}

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    cout << searchLL(head, 40) << endl;
    cout << recSearchLL(head, 40) << endl;

    printlist(head);
    return 0;
}

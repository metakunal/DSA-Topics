#include <bits/stdc++.h>
using namespace std;

//This is an important interview problem where one needs to find the middle of a linked list of a given linked list.
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
void printMiddle(Node *head)
{
    if (head == NULL)
        return;
    int count = 0;
    Node *curr;
    for (curr = head; curr != NULL; curr = curr->next)
        count++;
    curr = head;
    for (int i = 0; i < count / 2; i++)
        curr = curr->next;
    cout << curr->data;
}
//----------------------EFFICIENT------------------------
void printMiddleEff(Node *head)
{
    if (head == NULL)
        return;
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    printlist(head);
    cout << "Middle of Linked List: ";
    printMiddle(head);
    cout << endl;
    printMiddleEff(head);
    return 0;
}

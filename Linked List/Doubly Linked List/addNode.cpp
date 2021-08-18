#include <bits/stdc++.h>
using namespace std;

//Doubly linked list Insertion at given position
//Given a doubly-linked list, a position p, and an integer x.
//The task is to add a new node with value x at the position just after pth node in the doubly linked list.
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
void addNode(Node *head, int pos, int data)
{
    //creating and storing the new node with data in a pointer.
    Node *newnode = new Node(data);
    struct Node *cur = head;

    //using another pointer to traverse the linked list till position given.
    for (int i = 1; i < pos; i++)
        cur = cur->next;

    //if the node next to node at given position is null, we make the next
    //as new node and new node's previous link as this current node.
    if (cur->next == NULL)
    {
        cur->next = newnode;
        newnode->prev = cur;
    }
    else
    {

        //storing the next node to current node in link part(next) of new node.
        newnode->next = cur->next;

        //storing new node in link part(next) of current node.
        cur->next = newnode;

        //storing the new node in previous link part(prev) of the node which
        //was next to current node initially.
        newnode->next->prev = newnode;

        //store the current node in previous link part(prev) of new node.
        newnode->prev = cur;
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
    printlist(head);
    addNode(head, 1, 6);
    printlist(head);
    return 0;
}

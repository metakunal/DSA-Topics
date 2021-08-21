
//Program to detect and remove loop in linked list

#include <bits/stdc++.h>
using namespace std;

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
//------------CODE------------
void detectRemoveLoop(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (slow != fast)
        return;
    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

int main()
{
    Node *head = new Node(15);
    head->next = new Node(10);
    head->next->next = new Node(12);
    head->next->next->next = new Node(20);
    head->next->next->next->next = head->next;
    detectRemoveLoop(head);
    return 0;
}

//------------------One More Solution Using Hashing---------------
// void detectRemoveLoop(Node *head)
// {
//     unordered_set<Node *> s;
//     Node *prev = head;
//     for (Node *curr = head; curr != NULL; curr = curr->next)
//     {
//         if (s.find(curr) != s.end())
//         {
//             prev->next = NULL;
//         }

//         s.insert(curr);
//         prev = curr;
//     }
// }
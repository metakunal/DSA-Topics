#include <bits/stdc++.h>
using namespace std;
//This contains some variations of detect and remove loop
//1.Find the length of the loop.
//2.Find the first node of the loop.
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
//---This Functon gives the length of the loop as well as the frst node of the loop.
void detectRemoveLoop(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = slow->next;
            int len = 1;
            while (slow != fast)
            {
                slow = slow->next;
                len++;
            }
            cout << "The length of the loop is : " << len << endl;
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
    cout << "The first node of the loop is : " << fast->data << endl;
    //Removing Loop
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

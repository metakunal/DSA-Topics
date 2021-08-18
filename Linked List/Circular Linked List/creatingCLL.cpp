#include <bits/stdc++.h>
using namespace std;

//Program to create a simple implementation of CLL
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

int main()
{
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;
    return 0;
}

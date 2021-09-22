//Implementation of Queue using C++ STL
#include <iostream>
#include <queue> //Package for using queue.
using namespace std;
//Enqueue--push()
//Dequeue--pop()
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << " " << q.back() << endl;

    q.pop();

    cout << q.front() << " " << q.back() << endl;
    q.pop();
    q.pop();

    //Traversal of the Queue
    cout << "Traversing the Queue : " << endl;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "size" << q.size() << endl;
    while (q.empty() == false)
    {
        cout << q.front() << " " << q.back() << endl;
        q.pop();
    }

    return 0;
}
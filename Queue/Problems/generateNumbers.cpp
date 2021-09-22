#include <bits/stdc++.h>
#include <queue>
using namespace std;
//Given a number n, print first n numbers (in increasing order)
//such that all these numbers have digits in set eg.{5,6}
void printFirstN(int n)
{
    queue<string> q;

    q.push("5");
    q.push("6");

    for (int i = 0; i < n; i++)
    {
        string curr = q.front();

        cout << curr << " ";

        q.pop();

        q.push(curr + "5");
        q.push(curr + "6");
    }
}

int main()
{
    int n = 5;

    printFirstN(n);
}

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//Solutions of the stock span problem.
//----------------------NAIVE SOLUTION | O(n^2)---------------
void printSpan(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int span = 1;
        for (int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--)
            span++;
        cout << span << " ";
    }
}
//-------------------EFFECTIVE SOLUTION-------------
void printSpanEff(int arr[], int n)
{

    stack<int> s;
    s.push(0);
    cout << 1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        int span = s.empty() ? i + 1 : i - s.top();
        cout << span << " ";
        s.push(i);
    }
}
int main()
{
    int arr[] = {30, 20, 25, 28, 27, 29};
    int n = sizeof(arr) / sizeof(int);
    printSpan(arr, n);
    cout << endl;
    printSpanEff(arr, n);
    return 0;
}

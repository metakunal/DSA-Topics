#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//Given an array of distinct integers, find the NextGreater(position-wise closest and on the right side) of every array elements.

//----------------------NAIVE SOLUTION | O(n^2)---------------
void nextGreater(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                cout << arr[j] << " ";
                break;
            }
        }
        if (j == n)
            cout << -1 << " ";
    }
}
//-----------------EFFECTIVE--------------------
vector<int> nextGreaterEff(int arr[], int n)
{
    vector<int> v;
    stack<int> s;
    s.push(arr[n - 1]);
    v.push_back(-1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false && s.top() <= arr[i])
            s.pop();
        int ng = s.empty() ? -1 : s.top();
        v.push_back(ng);
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}
int main()
{

    int arr[] = {5, 15, 10, 8, 6, 12, 9, 18};
    int n = sizeof(arr) / sizeof(int);
    nextGreater(arr, n);
    cout << endl;
    for (int x : nextGreaterEff(arr, n))
    {
        cout << x << " ";
    }
    return 0;
}

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//Given an array of distinct integers, find the closest (positive wise) greater on left of every element.
// If there is no greater element on left, then print -1

//----------------------NAIVE SOLUTION | O(n^2)---------------
void printPrevGreater(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
            {
                cout << arr[j] << " ";
                break;
            }
        }
        if (j == -1)
            cout << -1 << " ";
    }
}
//-----------------EFFECTIVE--------------------
void printPrevGreaterEff(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    for (int i = 0; i < n; i++)
    {
        while (s.empty() == false && s.top() <= arr[i])
            s.pop();
        int pg = s.empty() ? -1 : s.top();
        cout << pg << " ";
        s.push(arr[i]);
    }
}
int main()
{

    int arr[] = {20, 30, 10, 5, 15};
    int n = sizeof(arr) / sizeof(int);
    printPrevGreater(arr, n);
    cout << endl;
    printPrevGreaterEff(arr, n);
    return 0;
}

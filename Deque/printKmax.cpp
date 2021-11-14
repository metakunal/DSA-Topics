// Maximums of all subarrays of size k
// We are given an array and a number k, we need to find maximums of all subarrays of size k.

#include <iostream>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

// Naive : O(n^2)
void printKmaxNaive(int arr[], int n, int k)
{
    for (int i = 0; i <= n - k; i++)
    {
        int max = arr[i];
        for (int j = i; j < i + k; j++)
        {
            if (arr[j] > max)
                max = arr[j];
        }
        cout << max << " ";
    }
}

//Efficient : O(n)
void printKMaxEff(int arr[], int n, int k)
{
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        cout << arr[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " ";
}
int main()
{
    int arr[] = {20, 40, 30, 10, 60};
    // printKmaxNaive(arr, 5, 3);
    printKMaxEff(arr, 5, 3);
    return 0;
}
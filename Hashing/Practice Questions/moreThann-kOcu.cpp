//Given an array of size n and an integer k.
//We need to print those elements which appear more than n/k times.
#include <bits/stdc++.h>
using namespace std;

//--------------------------------NAIVE SOLUTION----------------------

void printNByK(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int i = 1, count = 1;
    while (i < n)
    {
        while (i < n && arr[i] == arr[i - 1])
        {
            count++;
            i++;
        }
        if (count > n / k)
            cout << arr[i - 1] << " ";
        count = 1;
        i++;
    }
}
// TIME Complexity : O(nlog(n))
// Aux Space : O(1)

//--------------------------------Efficient Solution Using Unordered Set-------------------------------------------

void printNbyKeff(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (auto a : m)
    {
        if (a.second > n / k)
        {
            cout << a.first << " ";
        }
    }
}

int main()
{
    int a[] = {30, 10, 20, 20, 10, 20, 30, 30};
    int n = sizeof(a) / sizeof(int);

    cout << "Naive : " << endl;
    printNByK(a, n, 4);
    cout << "Efficient : " << endl;
    printNbyKeff(a, n, 4);

    return 0;
}
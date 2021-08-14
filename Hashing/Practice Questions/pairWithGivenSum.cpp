//C++ Program to count distinct elements in an array
#include <bits/stdc++.h>
using namespace std;

//--------------------------------NAIVE SOLUTION----------------------

bool isPair(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == sum)
                return true;
        }
        return false;
    }
}
// TIME Complexity : O(n^2)
// Aux Space : O(1)

//--------------------------------Efficient Solution Using Unordered Set-------------------------------------------
bool isPairEff(int arr[], int n, int sum)
{
    unordered_set<int> h;
    for (int i = 0; i < n; i++)
    {
        if (h.find(sum - arr[i]) != h.end())
        {
            return true;
        }
        else
        {
            h.insert(arr[i]);
        }
    }
    return false;
}

int main()
{
    int a[] = {10, 20, 10, 30, 20};
    int n = sizeof(a) / sizeof(int);

    cout << "Naive : " << endl;
    cout << isPair(a, n, 15) << endl;
    cout << "Efficient : " << endl;
    cout << isPairEff(a, n, 15);

    return 0;
}
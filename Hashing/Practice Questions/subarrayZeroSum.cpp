//C++ Program to find if we have a subarray with 0 sum
#include <bits/stdc++.h>
using namespace std;

//--------------------------------NAIVE SOLUTION----------------------

bool is0subarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];
            if (curr_sum == 0)
                return true;
        }
    }
    return false;
}
// TIME Complexity : O(n^2)
// Aux Space : O(1)

//--------------------------------Efficient Solution Using Unordered Set-------------------------------------------
bool is0subarrayEff(int arr[], int n)
{
    unordered_set<int> h;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (h.find(pre_sum) != h.end())
        {
            return true;
        }
        if (pre_sum == 0)
            return true;

        h.insert(pre_sum);
    }
    return false;
}

int main()
{
    int a[] = {-3, 2, 1, 4};
    int n = sizeof(a) / sizeof(int);

    cout << "Naive : " << endl;
    cout << is0subarray(a, n) << endl;
    cout << "Efficient : " << endl;
    cout << is0subarrayEff(a, n);

    return 0;
}
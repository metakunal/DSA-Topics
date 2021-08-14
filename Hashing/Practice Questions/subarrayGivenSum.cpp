//C++ Program to find if we have a subarray with the given sum
#include <bits/stdc++.h>
using namespace std;

//--------------------------------NAIVE SOLUTION----------------------

bool isSumSubarray(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];
            if (curr_sum == sum)
                return true;
        }
    }
    return false;
}
// TIME Complexity : O(n^2)
// Aux Space : O(1)

//--------------------------------Efficient Solution Using Unordered Set-------------------------------------------
bool isSumSubarrayEff(int arr[], int n, int sum)
{
    unordered_set<int> h;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == sum)
            return true;
        if (h.find(pre_sum - sum) != h.end())
        {
            return true;
        }

        h.insert(pre_sum);
    }
    return false;
}

int main()
{
    int a[] = {5, 8, 6, 13, 4, -1};
    int n = sizeof(a) / sizeof(int);

    cout << "Naive : " << endl;
    cout << isSumSubarray(a, n, 22) << endl;
    cout << "Efficient : " << endl;
    cout << isSumSubarrayEff(a, n, 22);

    return 0;
}
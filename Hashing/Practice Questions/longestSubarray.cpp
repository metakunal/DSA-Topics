//C++ Program to find if we have to find the length of longest subarray with given sum.
#include <bits/stdc++.h>
using namespace std;

//--------------------------------NAIVE SOLUTION----------------------

int maxLen(int arr[], int n, int sum)
{
    int l = 0, maxL = 0;
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];
            if (curr_sum == sum)
            {
                l = (j - i) + 1;
                maxL = max(l, maxL);
            }
        }
    }
    return maxL;
}
// TIME Complexity : O(n^2)
// Aux Space : O(1)

//--------------------------------Efficient Solution Using Unordered Map-------------------------------------------
int maxLenEff(int arr[], int n, int sum)
{
    unordered_map<int, int> h;
    int pre_sum = 0, maxL = 0, l = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];

        if (pre_sum == sum)
            maxL = i + 1;
        //Only inserting presum when not found before, because else it will update the position and our maximum longest subarray may reduce.
        if (h.find(pre_sum) == h.end())
            h.insert({pre_sum, i});
        if (h.find(pre_sum - sum) != h.end())
        {
            // auto it = h.find(pre_sum - sum);

            l = (i - (h[pre_sum - sum]));
            maxL = max(l, maxL);
        }
    }
    return maxL;
}

int main()
{
    int a[] = {8, 3, 1, 5, -6, 6, 2, 2};
    int n = sizeof(a) / sizeof(int);

    cout << "Naive : " << endl;
    cout << maxLen(a, n, 4) << endl;
    cout << "Efficient : " << endl;
    cout << maxLenEff(a, n, 4);

    return 0;
}
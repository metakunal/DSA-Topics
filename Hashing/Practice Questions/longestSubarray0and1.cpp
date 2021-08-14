//C++ Program to find longest subarray containing equal number of 0s and 1s.
#include <bits/stdc++.h>
using namespace std;

//--------------------------------NAIVE SOLUTION----------------------

int longest0and1(int arr[], int n)
{
    int maxL = 0;
    for (int i = 0; i < n; i++)
    {
        int count0 = 0, count1 = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
                count0++;
            else
                count1++;
            if (count0 == count1)
            {
                maxL = max(maxL, count0 + count1);
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

int longest0and1Eff(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            arr[i] = -1;
    }
    return maxLenEff(arr, n, 0);
}

int main()
{
    int a[] = {1, 1, 1, 0, 1, 1, 0};
    int n = sizeof(a) / sizeof(int);

    cout << "Naive : " << endl;
    cout << longest0and1(a, n) << endl;
    cout << "Efficient : " << endl;
    cout << longest0and1Eff(a, n);

    return 0;
}
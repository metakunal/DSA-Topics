//C++ Program to find longest subarray containing equal number of 0s and 1s.
#include <bits/stdc++.h>
using namespace std;

//--------------------------------NAIVE SOLUTION----------------------

int longestCommon(int a[], int b[], int n)
{
    int maxL = 0;
    for (int i = 0; i < n; i++)
    {
        int sumA = 0, sumB = 0;
        for (int j = i; j < n; j++)
        {
            sumA = sumA + a[j];
            sumB = sumB + b[j];
            if (sumA == sumB)
            {
                maxL = max(maxL, j - i + 1);
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
            l = (i - (h[pre_sum - sum]));
            maxL = max(l, maxL);
        }
    }
    return maxL;
}
int longestCommonEff(int a[], int b[], int n)
{
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = a[i] - b[i];
    }
    return maxLenEff(temp, n, 0);
}

int main()
{
    int a[] = {0, 1, 0, 1, 1, 1, 1};
    int b[] = {1, 1, 1, 1, 1, 0, 1};
    int n = sizeof(a) / sizeof(int);

    cout << "Naive : " << endl;
    cout << longestCommon(a, b, n) << endl;
    cout << "Efficient : " << endl;
    cout << longestCommonEff(a, b, n);

    return 0;
}
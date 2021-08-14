//Given an array, we need to find the longest subsequence that has consecutive elements.
// These consecutive elements may appear in any order in the subsequence.
#include <bits/stdc++.h>
using namespace std;

//--------------------------------NAIVE SOLUTION----------------------

int longestConsecutive(int arr[], int n)
{
    sort(arr, arr + n);
    int len = 1, maxL = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            len++;
        }
        //Taking this contdition as many times element might be same
        else if (arr[i] != arr[i - 1])
        {
            maxL = max(maxL, len);
            len = 1;
        }
    }
    return max(maxL, len);
}
// TIME Complexity : O(nlog(n))
// Aux Space : O(1)

//--------------------------------Efficient Solution Using Unordered Set-------------------------------------------

int longestConsecutiveEff(int arr[], int n)
{
    unordered_set<int> h(arr, arr + n);

    int res = 1;
    for (auto a : h)
    {
        //Checking when a-1 is there in set
        if (h.find(a - 1) == h.end())
        {
            int curr = 1;
            while (h.find(a + curr) != h.end())
                curr++;
            res = max(res, curr);
        }
    }
    return res;
}

int main()
{
    int a[] = {1, 3, 4, 3, 3, 2, 9, 10};
    int n = sizeof(a) / sizeof(int);

    cout << "Naive : " << endl;
    cout << longestConsecutive(a, n) << endl;
    cout << "Efficient : " << endl;
    cout << longestConsecutiveEff(a, n);

    return 0;
}
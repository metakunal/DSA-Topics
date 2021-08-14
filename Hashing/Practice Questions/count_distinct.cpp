//C++ Program to count distinct elements in an array
#include <bits/stdc++.h>
using namespace std;

//--------------------------------NAIVE SOLUTION----------------------

// int main()
// {
//     int arr[] = {1, 3, 3, 4, 4, 5};
//     int n = sizeof(arr) / sizeof(int);
//     int res = 0;
//     for (int i = 0; i < n; i++)
//     {
//         bool flag = false;
//         for (int j = 0; j < i; j++)
//         {
//             if (arr[i] == arr[j])
//             {
//                 flag = true;
//                 break;
//             }
//         }
//         if (flag == false)
//             res++;
//     }
//     cout << res;
// }

// TIME Complexity : O(n ^ 2);
// Aux Space : O(1);

//______________________________Better Solution Using Unordered Set_______________________________________
int count_distinct(int arr[], int n)
{
    unordered_set<int> m;
    for (int i = 0; i < n; i++)
    {
        m.insert(arr[i]);
    }
    return m.size();
}
int countDistinctImproved(int arr[], int n)
{
    unordered_set<int> s(arr, arr + n);
    return s.size();
}
int main()
{
    int arr[] = {1, 3, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    cout << count_distinct(arr, n);
    cout << countDistinctImproved(arr, n);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int prefix_sum(int arr[], int n)
{
    unordered_map<int, int> h;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        h[pre_sum] = i;
    }
    for (auto x : h)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
int main()
{
    int a[] = {5, 8, -4, -4, 9, -2, 2};
    int n = sizeof(a) / sizeof(int);

    cout << "Naive : " << endl;
    cout << prefix_sum(a, n) << endl;

    return 0;
}
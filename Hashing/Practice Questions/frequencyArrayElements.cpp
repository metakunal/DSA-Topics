//C++ Program to count distinct elements in an array
#include <bits/stdc++.h>
using namespace std;

//--------------------------------NAIVE SOLUTION----------------------

void count_freq_naive(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        //Checking if the element is seen befre, to avoid multiple printing of element.
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        //If seen before we ignore/skips the case
        if (flag == true)
            continue;
        //If not seen before count the frequency.
        int freq = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                freq++;
        }
        cout << arr[i] << " " << freq << endl;
    }
}

// TIME Complexity : O(n ^ 2);
// Aux Space : O(1);

//--------------------------------Better Solution Using Unordered Map-------------------------------------------
void count_frequency(int arr[], int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (auto a : m)
    {
        cout << a.first << " " << a.second << endl;
    }
}

int main()
{
    int arr[] = {1, 3, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    cout << "Naive : " << endl;
    count_freq_naive(arr, n);
    cout << "Efficient : " << endl;
    count_frequency(arr, n);

    return 0;
}
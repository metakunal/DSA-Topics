//Given a window of size k, we need to print the count of all distinct element in the window.

#include <bits/stdc++.h>
using namespace std;

//--------------------------------NAIVE SOLUTION----------------------

void printDistinct(int arr[], int n, int k)
{
    for (int i = 0; i <= n - k; i++)
    {
        int count = 0;
        for (int j = 0; j < k; j++)
        {
            bool flag = false;
            for (int p = 0; p < j; p++)
            {
                if (arr[i + j] == arr[i + p])
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
                count++;
        }
        cout << count << " ";
    }
}
// TIME Complexity : O((n-k)*k*k)
// Aux Space : O(1)

//--------------------------------Efficient Solution Using Unordered Set-------------------------------------------

void printDistinctEff(int arr[], int n, int k)
{
    unordered_set<int> h;
    for (int i = 0; i <= n - k; i++)
    {
        for (int j = i; j < i + k; j++)
        {
            h.insert(arr[j]);
        }
        cout << h.size() << " ";
        h.clear();
    }
}

//One more implementation using map
void printDistinctEff2(int arr[], int n, int k)
{
    map<int, int> m;

    for (int i = 0; i < k; i++)
    {
        m[arr[i]] += 1;
    }

    cout << m.size() << " ";

    for (int i = k; i < n; i++)
    {

        m[arr[i - k]] -= 1;

        if (m[arr[i - k]] == 0)
        {
            m.erase(arr[i - k]);
        }
        m[arr[i]] += 1;

        cout << m.size() << " ";
    }
}

int main()
{
    int a[] = {10, 10, 10, 10};
    int n = sizeof(a) / sizeof(int);

    cout << "Naive : " << endl;
    printDistinct(a, n, 3);
    cout << "Efficient : " << endl;
    printDistinctEff(a, n, 3);
    cout << "Efficient - 2" << endl;
    printDistinctEff2(a, n, 3);

    return 0;
}
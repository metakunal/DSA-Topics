//C++ Program to count distinct elements in an array
#include <bits/stdc++.h>
using namespace std;

//--------------------------------NAIVE SOLUTION----------------------

void count_freq_naive(int a[], int b[], int na, int nb)
{
    int res = 0;
    for (int i = 0; i < na; i++)
    {
        bool flag = false;
        //Checking if the element is seen before
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                flag = true;
                break;
            }
        }
        //If seen before we ignore/skips the case
        if (flag == true)
            continue;
        //If not seen before count the frequency.

        for (int j = 0; j < nb; j++)
        {
            if (a[i] == b[j])
            {
                res++;
                break;
            }
        }
    }
    cout << res << endl;
}

// TIME Complexity : O(m x (n+m))
// Aux Space : O(1)

//--------------------------------Better Solution Using Unordered Set-------------------------------------------
void intersection_count(int a[], int b[], int na, int nb)
{
    unordered_set<int> anew;
    int res = 0;
    for (int i = 0; i < na; i++)
    {
        anew.insert(a[i]);
    }
    for (int i = 0; i < nb; i++)
    {
        if (anew.count(b[i]) > 0)
        {
            res++;
            anew.erase(b[i]);
        }
    }
    cout << res;
}

int main()
{
    int a[] = {10, 20, 10, 30, 20};
    int b[] = {20, 10, 10, 40};
    int na = sizeof(a) / sizeof(int);
    int nb = sizeof(b) / sizeof(int);
    cout << "Naive : " << endl;
    count_freq_naive(a, b, na, nb);
    cout << "Efficient : " << endl;
    intersection_count(a, b, na, nb);

    return 0;
}
//C++ Program to count distinct elements in an array
#include <bits/stdc++.h>
using namespace std;

//--------------------------------Better Solution Using Unordered Set-------------------------------------------
void union_count(int a[], int b[], int na, int nb)
{
    unordered_set<int> s;

    for (int i = 0; i < na; i++)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < nb; i++)
    {
        s.insert(b[i]);
    }
    cout << s.size();
}

int main()
{
    int a[] = {10, 20, 10, 30, 20};
    int b[] = {20, 10, 10, 40};
    int na = sizeof(a) / sizeof(int);
    int nb = sizeof(b) / sizeof(int);

    cout << "Efficient : " << endl;
    union_count(a, b, na, nb);

    return 0;
}
#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
bool matching(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}

bool isBalanced(string &str)
{
    stack<char> s;
    for (char x : str)
    {
        if (x == '(' || x == '{' || x == '[')
            s.push(x);
        else
        {
            if (s.empty() == true)
                return false;
            else if (matching(s.top(), x) == false)
                return false;
            else
            {
                s.pop();
            }
        }
    }
    return (s.empty() == true);
}
int main()
{
    string str = "({[})";
    if (isBalanced(str))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}
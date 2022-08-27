// #include <iostream>
// #include <stack>
// using namespace std;
// bool isvalid(string s)
// {
//     int n = s.size();
//     stack<char> st;
//     bool ans = true;
//     for (int i = 0; i < n; i++)
//     {
//         if (s[i] == '{' || s[i] == '(' || s[i] == '[')
//         {
//             st.push(s[i]);
//         }
//         else if (s[i] == ')')
//         {
//             if (!st.empty() && st.top() == '(')
//             {
//                 st.pop();
//             }
//             else
//             {
//                 ans = false;
//                 break;
//             }
//         }
//         else if (s[i] == '}')
//         {
//             if (!st.empty() && st.top() == '}')
//             {
//                 st.pop();
//             }
//             else
//             {
//                 ans = false;
//                 break;
//             }
//         }
//         else if (s[i] == ']')
//         {
//             if (!st.empty() && st.top() == '[')
//             {
//                 st.pop();
//             }
//             else
//             {
//                 ans = false;
//                 break;
//             }
//         }
//     }
// }
// int main()
// {
//     string s = "{([])}";
//     if (isvalid(s))
//     {
//         cout << "valid";
//     }
//     else
//     {
//         cout << "invalid";
//     }
//     return 0;
// }

// CPP program to check for balanced brackets.
#include <bits/stdc++.h>
using namespace std;

// function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{
    stack<char> temp;
    for (int i = 0; i < expr.length(); i++) //
    {
        if (temp.empty())
        {
            temp.push(expr[i]); // pushing  the { ( [  in the stack
        }
        else if ((temp.top() == '(' && expr[i] == ')') || (temp.top() == '{' && expr[i] == '}') || (temp.top() == '[' && expr[i] == ']'))
        {
            temp.pop();
        }
        else
        {
            temp.push(expr[i]);
        }
    }
    if (temp.empty())
    {
        return true; // is valid
    }
    return false;
}

// Driver code
int main()
{
    string expr = "{(])}";

    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
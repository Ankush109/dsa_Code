#include <bits/stdc++.h>
using namespace std;
void sub(vector<int> &a, int i, int arr[], int n)
{

    if (i == n)
    {
        for (auto it : a)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    // for taking the next element:
    a.push_back(arr[i]);
    sub(a, i + 1, arr, n);
    a.pop_back();
    // for not taking the element:
    sub(a, i + 1, arr, n);
}

int main()
{
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> a;
    sub(a, 0, arr, n);
    return 0;
}
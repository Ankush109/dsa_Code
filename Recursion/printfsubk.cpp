#include <bits/stdc++.h>
using namespace std;

bool sub(vector<int> &a, int i, int sum, int s, int n, int arr[])
{
    if (i == n)
    {
        if (s == sum)
        {
            for (auto it : a)
            {
                cout << it << " ";
            }
            cout << endl;

            return true;
        }
        // condition not satisfied
        return false;
    }

    a.push_back(arr[i]);
    s += arr[i];
    if (sub(a, i + 1, sum, s, n, arr) == true)
    {
        return true;
    }
    a.pop_back();
    s -= arr[i];
    // for not picking
    if (sub(a, i + 1, sum, s, n, arr) == true)
    {
        return true;
    }
    return false;
}
int main()
{
    int arr[] = {1, 2, 1};
    int sum = 2;
    int n = 3;
    vector<int> a;
    sub(a, 0, sum, 0, n, arr);
    return 0;
}
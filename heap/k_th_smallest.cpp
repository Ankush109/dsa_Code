#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> max; // max heap
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        max.push(arr[i]);
        if (max.size() > k)
        {
            max.pop();
        }
    }

    return max.top();
}
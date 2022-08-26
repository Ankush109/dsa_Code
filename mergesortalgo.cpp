#include <iostream>
using namespace std;
void merge(int A[], int start, int mid, int end)
{
    // stores the starting position of both parts in temporary variables.
    int p = start, q = mid + 1;

    int Arr[end - start + 1], k = 0;

    for (int i = start; i <= end; i++)
    {
        if (p > mid) // checks if first part comes to an end or not .
            Arr[k++] = A[q++];

        else if (q > end) // checks if second part comes to an end or not
            Arr[k++] = A[p++];

        else if (A[p] < A[q]) // checks which part has smaller element.
            Arr[k++] = A[p++];

        else
            Arr[k++] = A[q++];
    }
    for (int p = 0; p < k; p++)
    {
        /* Now the real array has elements in sorted manner including both
             parts.*/
        A[start++] = Arr[p];
    }
}
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int n;
    cout << "enter the size of the array"
         << " ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "enter the number you want to insert in the array of applying merge_sort";
        cin >> arr[i];
    }
    cout << "**************APPLYING MERGE_SORT*****************";
    mergesort(arr, 0, n);
    for (int i = 0; i < n; i++)
    {

        cout << arr[i];
    }
}

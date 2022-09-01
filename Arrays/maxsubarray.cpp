#include <iostream>
#include <climits>
using namespace std;
// brute force approach
int main()
{
    int n;

    cout << "enter the size";
    cin >> n;
    int arr[n];
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {

                sum += arr[k];
            }
            // after getting the sum;
            max_sum = max(max_sum, sum);
            cout << endl;
        }
    }
    cout << "the max_sum is " << max_sum;
    return 0;
}
#include <stdio.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void sorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // selection sort
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void binarysearch(int arr[], int n, int element)
{
    int low, mid, high;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            printf("\n The element is found at index %d", mid);
            break;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}
int main()
{
    // int n;
    // printf("Enter number of elements: ");
    // scanf("%d", &n);
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     printf("\n Enter an element: ");
    //     scanf("%d", &arr[i]);
    // }
    // printf("\n Here is your array: ");
    // display(arr, n);
    // int element;
    // /*int element;
    // printf("\n Enter the element to be searched: ");
    // scanf("%d", &element);
    // linearsearch(arr,n,element);*/
    // sorted(arr, n);
    // printf("\n Sorted array: ");
    // display(arr, n);
    // printf("\n Enter element to be found: ");
    // scanf("%d", element);

    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("\n Enter an element: ");
        scanf("%d", &arr[i]);
    }
    sorted(arr, n);
    printf("\n Sorted array: ");
    display(arr, n);
    printf("\n Enter element to be found: ");
    int element;
    scanf("%d", &element);
    binarysearch(arr, n, element);
    return 0;
}
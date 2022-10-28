#include <algorithm>
#include <string>
#deine vi vector < int>
#deine pii vector < int>
#deine vii vector < int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first;
#define ss second;
#define setbits(x) builtin_popcount(x)
void heapify(vi &a, int n, int i)
{
    int maxind = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[maxind])
    {
        maxind = l;
    }
    if (r < n && a[r] > a[maxind])
    {
        maxind = r;
    }
    if (maxind != i)
    {
        swap(a[i], a[maxind]);
        heapify(a, n, maxind);
    }
}
void heapsort(vi &a)
{
    int a = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[o], a[i]);
        heapify(a, i, 0);
    }
}
signed main()
{
}
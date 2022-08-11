#include <iostream>
using namespace std;
void f(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << "ankush";
    f(i + 1, n);
}
int main()
{
    int n;
    int i = 1;
    cin >> n;
    f(i, n);
    return 0;
}
#include <iostream>
using namespace std;

bool check(string &s, int i)
{
    int n = s.size();
    if (i >= n / 2)
        return true;
    if (s[i] != s[n - i - 1])
        return false;
    return check(s, i + 1);
}
int main()
{
    string str = "MADAM";
    cout << check(str, 0);

    return 0;
}
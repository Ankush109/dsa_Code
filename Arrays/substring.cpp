#include <iostream>
using namespace std;
void subes(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    subes(ros, ans);
    subes(ros, ans + ch);
}
int main()
{
    subes("ANS", "");

    return 0;
}
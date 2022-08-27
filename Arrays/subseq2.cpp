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
    int code = ch;
    string ros = s.substr(1);
    subes(ros, ans);
    subes(ros, ans + ch);
    subes(ros, ans + to_string(code));
}
int main()
{
    subes("AB", "");

    return 0;
}
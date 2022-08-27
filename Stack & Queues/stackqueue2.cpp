#include <iostream>
#include <queue>
using namespace std;
class stack
{
    int n;
    queue<int> q1;
    queue<int> q2;

public:
    stack()
    {
        n = 0;
    }
    void pop()
    {
        if (q1.empty())
        {
            return;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        n--;
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void push(int x)

    {
        q1.push(x);
        n++;
    }
    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
    }
    int size()
    {
        return n;
    }
};
int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    return 0;
}
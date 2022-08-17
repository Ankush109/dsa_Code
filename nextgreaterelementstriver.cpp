//
int nge[n], stack<int> st;
for (int i = 0; i < 2n - 1; i++)
{
    while (!st.empty() && st.top() <= a[i % n])
    // time complexity -> o(2n)
    // making a copy to iterate to the circular array type:
    // for eg:
    // 1 2 3 4 5 6 7 8 9 10
    // 6 7 9 4 5 6 7 9 4 5
    // i % n = i of the prev part
    {
        st.pop();
    }
    if (i < n)
    {
        if (st.empty() == false)
        {
            nge[i] = st.top();
        }
        else
        {
            nge[i] = -1;
        }
        st.push(a[i % n]);
    }
}

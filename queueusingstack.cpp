// #include "bits/stdc++.h"
// #include <stack>
// using namespace std;
// class que
// {
//     stack<int> s1;
//     stack<int> s2;

// public:
//     void push(int x)
//     {
//         s1.push(x);
//     }
//     int pop()
//     {
//         if (s1.empty() && s2.empty())
//         {
//             cout << "queue is empty";
//             return -1;
//         }
//         if (s2.empty())
//         {
//             while (!s1.empty())
//             {
//                 s2.push(s1.top());
//                 s2.pop();
//             }
//         }
//         int topval = s2.top();
//         s2.pop();
//         return topval;
//     }
//     bool empty()
//     {
//         if (s1.empty() && s2.empty())
//         {
//             return true;
//         }
//         return false;
//     }
// };
// int main()
// {
//     que q;
//     q.push(1);
//     q.push(2);
//     cout << q.pop() << "\n";
//     return 0;
// }
// CPP program to implement Queue using
// two stacks with costly enQueue()
#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    stack<int> s1, s2;

    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Push item into s1
        s1.push(x);

        // Push everything back to s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        // if first stack is empty
        if (s1.empty())
        {
            cout << "Q is Empty";
            exit(0);
        }

        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
};

// Driver code
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    return 0;
}

#include <iostream>
#include <list>
using namespace std;
void display(list<int> &list)
{
    list<int>::iterator it;
    for (it = list.begin(); it != list.end(); it++)
    {
        cout << *it << " ";
    }
}
int main()
{
    list<int> list1;
    list<int> list2(7);
    list1.push_back(5);
    list1.push_back(7);
    // list<int>::iterator iter;
    // iter = list1.begin();
    // cout << *iter;
    // iter++;
    // cout << *iter;
    display(list1);
    return 0;
}
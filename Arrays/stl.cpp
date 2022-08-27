#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        /* code */
        cout << v[i] << " ";
    }
}
int main()
{
    vector<int> vec1;
    int ele, size;
    cout << "enter the size of your vector" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        /* code */
        cout << "enter an element to add to this vector";
        cin >> ele;
        vec1.push_back(ele);
    }
    // vec1.pop_back();
    // display(vec1);
    vector<int>::iterator iter = vec1.begin();
    vec1.insert(iter+1,4, 566);
    display(vec1);
    return 0;
}
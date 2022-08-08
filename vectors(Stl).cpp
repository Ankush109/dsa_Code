#include <iostream>
#include <vector>
using namespace std;
void explainvector()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<pair<int, int>> vec; // {1,3}
    v.push_back({1, 2});
    v.emplace_back(1, 2);
    vector<int> v2(v) // copy vector v
        vector<int>
            v(5, 100);                    // {100,100,100,100,100}
    vector<int>::iterator it = v.begin(); //{10,20,30,40,_}
    cout << *(it) << " ";
    //* will point the value of a allocated memory
    vector<int>::iterator it = v.end(); // will point to the location after last element
    // r.begin() -> will point the last element in the array
    // r.end () -> will point to the element before the first element
    it++;
    // vector<int> :: iterator ->auto
    for (auto it : v)
    // {
    //     10, 20, 30  it -> 10 ; it -> 20 ;it->30
    // }
    {
        cout << it << " ";
    }

    // erase(i) // for a single element

    // .erase(st,end)  {1,2,3,4,5,6}

    // st -> v.begin()+1
    //  will start at st and stop before end
    // end -> begin()+3

    // insert function
    vector<int> v(2, 100);
    v.insert(v.begin(), 300);
    v.insert(v.begin() + 1, 2, 10);
    // .insert(st,numberofoccurence,the number you want to insert)

    vector<int>
        copy(2, 50);
    // pop_back() will pop the last most element
    v1.swap(v2);
}
int main()
{
    return 0;
}
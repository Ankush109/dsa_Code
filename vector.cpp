#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    // vector<int>::iterator it;
    // for (it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    v.pop_back();

    vector<int> v2(3, 50);
    // 50 50 50
    swap(v, v2);
    for (auto element : v)
    {
        cout << element << endl;
    }
    for (auto element : v2)
    {
        cout << element << endl;
    }
    sor(v.begin(), v.end());

    // STL by striver:-
    arr<int, 3> arr;       // ->{?,?,?}
    arr<int, 3> arr = {1}; // -> {1,0,0,0,0}
    array<int, 5> arr;
    arr.fill(5); // fill all the elements in 5
    arr.at(index);
    for (int i = 0; i < 5; i++)
    {
        cout << arr.at(i) << "";
    }
    // iterators: -
    //  begin(),end(),ebegin(),rend()
    // rbegin() - > will be the last element  of the array
    // rend() -> before the first element
    // end() -> will point the next of the last element in the array
    array<int, 5> arr = {1,
                         2,
                         3,
                         4,
                         5};
    for (auto it; arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " ";
    }
    auto it // -> means the element itself
        for (auto it : arr)
    {
        cout << it < "";
    }
    cout << arr size();
    cout << arr.front() // arr.at(0)
                        // arr.back()
            return 0;
    W
        // vector by striver
        int arr[50] // static allocation so we use vector
                    // max size of an array of int -> 10^6

        // globally the size of int array ->10^7

        vector<int>
            arr;
    arr.push_back(i);
    arr.emplace_back(i) // -> takes lesser time than push back

        vector.clear() // -> will clears all the elements at once {}
                       // to copy
        vector<int>
            vec3(vec2)

        // lower bound, upper bound

        swap(v1, v2); // will swap the two vector
    // to define 2-d vectors
    vector<vector<int>> vec;

    vector<int> raj1;
    raj1.push_back(1);
    raj1.push_back(2);

    // iterating through the vector itself

    for (auto vctr : vec)
    {
        for (auto it : vctr)
            cout << it << "";
    }
    cout << endl;

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << "";
        }
    }
}

// define 10 X 20
vector<vector<int>> vec(10, vector<int>(20, 0));

arr[] = {2, 3, 4, 5} set<int> st;
int n;
for (int i = 0; i < n; i++)
{
    int x;
    cin >> x;
    st.insert(x);

    st.erase(st.begin())
}
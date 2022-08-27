#include <iostream>
using namespace std;
// pairs
void explainpairs()
{
    pair<int, int> p = {1, 2};
    cout << p.first << " " << p.second;
    // making pair inside a pair => nested pair
    pair<int, pair<int, int>> p = {1, {1, 2}};
    cout << p.first << " " << p.second.second << " " << p.second.first;
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[i].second;
}
int main()
{
    return 0;
}
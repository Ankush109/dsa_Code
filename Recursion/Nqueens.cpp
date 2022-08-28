
#include <iostream>
#include <vector>
using namespace std;
bool check(int i, int j, vector<vector<int>> grid)
{
    int size = grid.size();
    for (int row = i - 1; row > 0; row--)

    {
        if (grid[row][j])
            return false;
    }
    int r = i - 1;
    int c = j + 1;
    while (r >= 0 && c >= 0)
    {
        if (grid[r][c])
            return false;
        r--;
        c--;
    }
    r = i - 1;
    c = j + 1;
    while (r >= 0 && c < size)
    {
        if (grid[r][c])
            return false;
        r--;
        c++;
    }
    return true;
}
bool solve(int i, vector<vector<int>> &grid)
{
    int n = grid.size();
    if (i == n)
        return true;
    for (int j = 0; j < n; j++)
    {
        if (check(i, j, grid))
        {
            grid[i][j] = 1;
            if (solve(i + 1, grid))
                return true;
            else
            {
                grid[i][j] = 0;
            }
        }
    }
}
int main()
{
    vector<vector<int>> grid(8, vector<int>(8, 0));
    if (solve(0, grid))
    {
        cout << "Possible"
             << "\n";
        for (auto &v : grid)
        {
            for (auto &x : v)
                cout << x << " ";
            cout << "\n";
        }
    }
    else
        cout << "Not Possible"
             << "\n";
}
// grid[i][j] = 1 denotes that there is a queen at that point
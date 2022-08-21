// C++ recursive function to
// solve tower of hanoi puzzle
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int *stepcount, int n, char source,
                  char dest, char helper)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(stepcount, n - 1, source, helper, dest); // moving to helper rod
    printf("\n Step no %d  : Transfer from  disk %d from   % c to %c", ++(*stepcount), n, source, dest);
    towerOfHanoi(stepcount, n - 1, helper, dest, source); // from helper to dest
}

// Driver code
int main()
{
    int stepcount = 0;
    int n = 4;                                  // Number of disks
    towerOfHanoi(&stepcount, n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}

// This is code is contributed by rathbhupendra
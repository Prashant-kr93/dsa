/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.
 Input format :
The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.
Output format :
Print the minimum cost to reach the destination.
Constraints :
1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76
Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18
*/

#include <iostream>
#include <climits>
using namespace std;

// Brute-Force recursive approach
int minCostPath_helper(int **input, int m, int n, int si, int sj)
{
    if (si == m - 1 && sj == n - 1)
    {
        return input[si][sj];
    }
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    if (si < m && sj + 1 < n)
    {
        x = minCostPath_helper(input, m, n, si, sj + 1);
    }
    if (si + 1 < m && sj < n)
    {
        y = minCostPath_helper(input, m, n, si + 1, sj);
    }
    if (si + 1 < m && sj + 1 < n)
    {
        z = minCostPath_helper(input, m, n, si + 1, sj + 1);
    }

    int smallAns = min(x, min(y, z));
    return smallAns + input[si][sj];
}

int minCostPath(int **input, int m, int n)
{
    return minCostPath_helper(input, m, n, 0, 0);
}

// Memoization(top - down) approach
int minCostPath_Mem_helper(int **input, int m, int n, int si, int sj, int **ans)
{
    if (si == m - 1 && sj == n - 1)
    {
        return input[si][sj];
    }

    // check whether o/p is already present
    if (ans[si][sj] != -1)
    {
        return ans[si][sj];
    }

    // calculate
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    if (si < m && sj + 1 < n)
    {
        x = minCostPath_Mem_helper(input, m, n, si, sj + 1, ans);
    }
    if (si + 1 < m && sj < n)
    {
        y = minCostPath_Mem_helper(input, m, n, si + 1, sj, ans);
    }
    if (si + 1 < m && sj + 1 < n)
    {
        z = minCostPath_Mem_helper(input, m, n, si + 1, sj + 1, ans);
    }

    int smallAns = min(x, min(y, z));
    ans[si][sj] = smallAns + input[si][sj];
    return ans[si][sj];
}

int minCostPath_Memoization(int **input, int m, int n)
{
    int **ans = new int *[m];
    for (int i = 0; i < m; i++)
    {
        ans[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = -1;
        }
    }
    int res = minCostPath_Mem_helper(input, m, n, 0, 0, ans);
    for (int i = 0; i < m; i++)
    {
        delete[] ans[i];
    }
    delete[] ans;
    return res;
}

// DP (bottom-up) approach
int minCostPath_DP(int **input, int m, int n)
{
    
    int**ans = new int*[m];
    for (int i = 0; i < m; i++)
    {
        ans[i] = new int[n];
    }
    //fill the last cell i.e:- destination
    ans[m - 1][n - 1] = input[m - 1][n - 1];
    
    // fill last row (right-to-left)
    for (int j = n - 2; j >= 0; j--)
    {
        ans[m - 1][j] = ans[m - 1][j + 1] + input[m - 1][j];
    }
    
    // fill last column(bottom to top)
    for (int i = m - 2; i >= 0; i--)
    {
        ans[i][n - 1] = ans[i + 1][n - 1] + input[i][n - 1];
    }

    //fill remaining cells
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            ans[i][j] = min(ans[i][j + 1] + input[i][j], min(ans[i + 1][j + 1] + input[i][j], ans[i + 1][j] + input[i][j]));
        }
    }
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return ans[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n;
    cin >> m >> n;
    int **input = new int *[m];
    for (int i = 0; i < m; i++)
    {
        input[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout<<input[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout << minCostPath(input, m, n) << endl;
    cout << minCostPath_Memoization(input, m, n) << endl;
    cout<<"dp:\n";
    cout << minCostPath_DP(input, m, n) << endl;
}
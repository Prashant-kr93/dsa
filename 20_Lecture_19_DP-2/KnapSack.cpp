#include <iostream>
using namespace std;

// Brute-Force recursive approach
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    if (n <= 0 || maxWeight == 0)
    {
        return 0;
    }
    // If first weight is already greater than maxm capacity then skip that and make further recursive call
    //If weight of the nth item more than Knapsack capacity W,
    // then this item cannot be included in the optimal solution
    if (weights[0] > maxWeight)
    {
        return knapsack(weights + 1, values + 1, n - 1, maxWeight);
    }

    //otherwise
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included


    // now there is 2 recursive call for one for if we put first
    // weight in knapsack, another call for skip first weight
    int remainingCapacity = maxWeight - weights[0];
    int a = values[0] + knapsack(weights + 1, values + 1, n - 1, remainingCapacity);
    int b = knapsack(weights + 1, values + 1, n - 1, maxWeight);
    return max(a, b);
}

// Memoization(top-down) approach
int knapsack_helper(int *wt, int *v, int n, int mw, int **ans)
{
    if (n == 0 || mw == 0)
    {
        return 0;
    }
    // check if ans already exist
    if (ans[n][mw] != -1)
    {
        return ans[n][mw];
    }

    // recursive call

    int res;
    if (wt[0] > mw)
    {
        res = knapsack_helper(wt + 1, v + 1, n - 1, mw, ans);
    }
    else
    {
        int a = v[0] + knapsack_helper(wt + 1, v + 1, n - 1, mw - wt[0], ans);
        int b = knapsack_helper(wt + 1, v + 1, n - 1, mw, ans);
        res = max(a, b);
    }
    // save for future
    ans[n][mw] = res;

    return ans[n][mw];
}

int knapsack_mem(int weights[], int values[], int n, int maxWeight)
{
    int **ans = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = new int[maxWeight + 1];
        for (int j = 0; j < maxWeight + 1; j++)
        {
            ans[i][j] = -1;
        }
    }
    return knapsack_helper(weights, values, n, maxWeight, ans);
}

// int knapsack_helper(int weights[], int values[], int n, int i, int mW, int **ans)
// {
//     if (i == n || mW == 0)
//     {
//         return 0;
//     }
//     // check if ans already exist
//     if (ans[i][mW] != -1)
//     {
//         return ans[i][mW];
//     }

//     // recursive call
//     if (weights[i] > mW)
//     {
//         ans[i][mW] = knapsack_helper(weights, values , n, i + 1, mW, ans);
//     }
//     else
//     {
//         int remainingCap = mW - weights[i];
//         int a =values[i] + knapsack_helper(weights, values, n , i + 1, remainingCap, ans);
//         int b = knapsack_helper(weights, values, n , i + 1, mW, ans);
//         ans[i][mW] = max(a, b);
//     }
//     return ans[i][mW];
// }

// int knapsack_mem(int weights[], int values[], int n, int maxWeight)
// {
//     int **ans = new int *[n + 1];
//     for (int i = 0; i < n + 1; i++)
//     {
//         ans[i] = new int[maxWeight + 1];
//         for (int j = 0; j < maxWeight + 1; j++)
//         {
//             ans[i][j] = -1;
//         }
//     }
//     return knapsack_helper(weights, values, n, 0, maxWeight, ans);
// }

// DP(bottom-up) approach
//T.C : O(n*mw)
//S.C : O(n*mw)
int knapsack_DP(int *weight, int *value, int n, int maxWeight)
{
    int **DP = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        DP[i] = new int[maxWeight + 1];
    }
    // fill last row
    for (int j = 0; j < maxWeight + 1; j++)
    {
        DP[n][j] = 0; // base case si == n then 0;
    }
    // fill last col
    for (int i = 0; i < n + 1; i++)
    {
        DP[i][0] = 0; // base case if mw == 0 then 0;
    }

    // fill remaing cell
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j < maxWeight + 1; j++) // j represent maxm wt allowed at ith position
        {
            if (weight[i] > j)
            {
                DP[i][j] = DP[i + 1][j];
            }
            else
            {
                DP[i][j] = max(DP[i + 1][j], value[i] + DP[i + 1][j - weight[i]]);
            }
        }
    }
    return DP[0][maxWeight];
}

//Dp optimized space complexity
//S.C : O(W)//W is maxm weight capacity of knapsack
int knapsack_DP_OpS(int wt[],int val[], int n, int mw){
    int **DP = new int*[2];
    for (int i = 0; i < 2; i++)
    {
        DP[i]= new int[mw + 1];
        for (int j = 0; j < mw + 1; j++)
        {
            DP[i][j] = 0;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= mw; j++)
        {
            if (wt[i] > j)
            {
                DP[i%2][j] = DP[(i+1) %2][j];
            }
            else{
                int a = val[i] + DP[(i+1) %2][j-wt[i]];
                int b = DP[(i+1) % 2][j];
                DP[i%2][j] = max(a,b);
            }
        }
    }
    return (n%2 == 0) ? DP[1][mw] : DP[0][mw];

}

int main()
{
    int n;
    cin >> n;
    int *weights = new int[n];
    int *values = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    int maxWeight;
    cin >> maxWeight;
    cout << knapsack(weights, values, n, maxWeight) << endl;
    cout << knapsack_mem(weights, values, n, maxWeight) << endl;
    cout << knapsack_DP(weights, values, n, maxWeight) << endl;
    cout << knapsack_DP_OpS(weights, values, n, maxWeight) << endl;

    delete[] weights;
    delete[] values;
    return 0;
}
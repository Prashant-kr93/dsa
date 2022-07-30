#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <algorithm>
using namespace std;

int lis(int prev, int curr, vector<int> &arr)
{
    if (curr == arr.size())
    {
        return 0;
    }
    int first = 0;
    if (prev == -1 || arr[prev] < arr[curr])
    {
        first = 1 + lis(curr, curr + 1, arr);
    }
    int sec = lis(prev, curr + 1, arr);
    return max(first, sec);
}

int longestIncreasingSubsequence(int *arr, int n, vector<int> &lis)
{
    if (n <= 0)
    {
        return 0;
    }
    int ans = INT_MIN;
    if (arr[0] < arr[1])
    {
        ans = max(ans, 1 + longestIncreasingSubsequence(arr + 1, n - 1, lis));
    }
    else
    {
        ans = max(ans, longestIncreasingSubsequence(arr + 1, n - 1, lis));
    }
    return ans;
}

int longestIncreasingSubsequences(int *arr, int n)
{
    int *ans = new int[n];
    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        ans[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j])
            {
                ans[i] = max(ans[i], 1 + ans[j]);
            }
        }
    }
    sort(ans, ans + n);
    return ans[n - 1];
}

//Using binary search(T.C: O(nlogn) ans s.c:O(n))
int lis_BinarySearch(int *arr, int n){
    vector<int> temp;
    temp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> lis;
    // cout<<longestIncreasingSubsequence(arr,n,lis)<<endl;
    cout << longestIncreasingSubsequences(arr, n) << endl;
    cout<<lis_BinarySearch(arr,n)<<endl;
    // cout<<liseq(arr,n)<<endl;
}
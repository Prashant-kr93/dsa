/*
A thief wants to loot houses. He knows the amount of money in each house. 
He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
Output format :
Print the the maximum money that can be looted.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, 
and all the other possible combinations would result in less than 90.
*/


#include<iostream>
using namespace std;

int maxMoneyLooted(int *arr, int n,int si){
    if (si>=n)
    {
        return 0;
    }
    int a = arr[si] + maxMoneyLooted(arr,n,si+2);
    int b = maxMoneyLooted(arr,n,si+1);
    // int a = arr[si] + maxMoneyLooted(arr,n,si+2);
    // int b = arr[si+1] + maxMoneyLooted(arr,n,si+3);
    return max(a,b);
}

//Memoization (top-down) approach
int maxMoneyLooted_helper(int *arr, int n, int *ans){
    if (n <= 0)
    {
        return 0;
    }
    //check ans already exist or not
    if (ans[n] != -1)
    {
        return ans[n];
    }
    //calculate 
    int a = arr[0] + maxMoneyLooted_helper(arr+2,n-2,ans);//take first element in ans
    int b = maxMoneyLooted_helper(arr+1,n-1,ans); // leave first element
    //save for future
    ans[n] = max(a,b);
    return ans[n];
}
int maxMoneyLooted(int *arr, int n){
    int *ans = new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        ans[i] = -1;
    }
    return maxMoneyLooted_helper(arr,n,ans);
}


int maxMoneyLooted_DP(int *arr, int n){
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = arr[0];
    for (int i = 2; i <= n; i++)
    {
        ans[i] = max(ans[i-1],ans[i-2] + arr[i-1]);
    }
    return ans[n];
}


//

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    // int ans = maxMoneyLooted(arr,n,0);
    // ans = maxMoneyLooted(arr,n);
    cout<<maxMoneyLooted(arr,n,0)<<endl;
    cout<<maxMoneyLooted(arr,n)<<endl;
    cout<<maxMoneyLooted_DP(arr,n)<<endl;
    delete[] arr;
}
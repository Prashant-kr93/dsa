#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

//Brute-Force recursive approach
int minCount(int n){
    if (n<= 1)
    {
        return n;
    }
    int ans = INT_MAX;
    for (int i = 1,j = 1; j <= n;j = i*i,i++)
    {
        ans = min(ans,minCount(n-j));
    }
    return 1 + ans;
}

//Memoization(top-down) approach
int minCount_helper(int n, int ans[]){
    if ( n<= 1)
    {
        return n;
    }
    //check whether o/p is already present or not
    if (ans[n] != -1)
    {
        return ans[n];
    }

    int val = INT_MAX;
    for (int i = 1,j = 1; j <= n; j = i*i,i++)
    {
        val = min(val,minCount_helper(n-j,ans));
    }
    
    //save for future use
    ans[n] = 1 + val;
    return ans[n];
}
int minCount_Memoization(int n){
    int *ans = new int[n+1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    int res = minCount_helper(n,ans);
    delete[] ans;
    return res;
}

int minCount_Dp(int n){
    int *ans = new int[n+1];
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i == pow((int)(sqrt(i)) , 2))
        {
            ans[i] = 1;
            continue;
        }
        ans[i] = INT_MAX;
        for (int j = 0; j*j <= i; j++)
        {
            ans[i] = min(ans[i],ans[i-(j*j)]);
        }
        ans[i] = 1 + ans[i];
        // int np = (int)(pow((int)(sqrt(i)) ,2));
        // ans[i] = ans[(int)(pow((int)(sqrt(i)) ,2))] + ans[(i - (int)(pow((int)(sqrt(i)), 2)))];
        // if (i-np == (int)(pow((int)(sqrt(i-np)) ,2)))
        // {
        //     ans[i] += 
        // }
        
    }
    int res = ans[n];
    delete[] ans;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    cout<<minCount(n)<<endl;
    cout<<minCount_Memoization(n)<<endl;
    cout<<minCount_Dp(n)<<endl;
}
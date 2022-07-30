#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
#define mod 1000000007

//Brute-force Recursive approach
int balancedBTs(int h){
    if (h <= 1)
    {
        return 1;
    }
    // int mod = 1000000007;
    int x = balancedBTs(h-1);
    int y = balancedBTs(h-2);

    int temp1 = (int)(((ll)(x)*x) % mod);
    int temp2 = (int)((2*(ll)(x) * y) % mod);
    int ans = (temp1 + temp2) % mod;
    return ans;
    // return (a*a + a*b + b*a)%mod;
}

//Memoization(top-down) approach
int balancedBTs_helper(int h, int ans[]){
    if (h<=1)
    {
        return 1;
    }

    //check if o/p is already present or not?
    if (ans[h] != -1)
    {
        return ans[h];
    }
    
    //calculate
    // int mod = (int)(pow(10,9)) + 7;
    int x = balancedBTs_helper(h-1,ans);
    int y = balancedBTs_helper(h-2,ans);
    //tricky here is that store the value as buffer storage
    int temp1 = (int)(((ll)(x)*x)%mod);
    int temp2 = (int)((2*(ll)(x)*y) % mod);
    ans[h] = (temp1 + temp2) % mod; // save for future;
    return ans[h];
    
    
}

int balancedBTs_Memoization(int h){
    int *ans = new int[h+1];
    for (int i = 0; i <= h; i++)
    {
        ans[i] = -1;
    }
    int res = balancedBTs_helper(h,ans);
    delete[] ans;
    return res;
}

//DP(bottom-up) approach
int balancedBTs_DP(int h){
    int *ans = new int[h+1];
    ans[0] = 1;
    ans[1] = 1;

    for (int i = 2; i <= h; i++)
    {
        int x = ans[i-1];
        int y = ans[i-2];
        int temp1 = (int)(((ll)(x)*(x))%mod);
        int temp2 = (int)((2*(ll)(x) * y) % mod);
        ans[i] = (temp1 + temp2) % mod;
    }
    int res = ans[h];
    delete[] ans;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h;
    cin>>h;
    cout<<balancedBTs(h)<<endl;
    cout<<balancedBTs_Memoization(h)<<endl;
    cout<<balancedBTs_DP(h)<<endl;
}
#include<iostream>
using namespace std;

//Brute-force recursive approach
// long staircase(int n){

//    if (n==0 || n == 1)
//    {
//        return 1;
//    }
//    if (n== 2)
//    {
//        return n;
//    }
//    return staircase(n-1) + staircase(n-2) +staircase(n-3);
// }



// Memoization approach(top-down approach)
long staircase(long n, long ans[]){
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if(n==2) return n;

    // check whether o/p already present or not
    if (ans[n] != -1)
    {
        return ans[n];
    }
    
    //calculate
    long a = staircase(n-1,ans);
    long b = staircase(n-2,ans);
    long c = staircase(n-3,ans);

    ans[n] = a + b + c;

    return ans[n];
}
long staircase(int n){
    long *ans = new long[n+1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    long res = staircase(n,ans);
    delete[] ans;
    return res;
}


//DP(bottom-up) approach
long stairCase_Dp(int n){
    long *ans = new long[n+1];
    ans[0] = 1, ans[1] = 1, ans[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    }
    long res = ans[n];
    delete[] ans;
    return res;
}


int main(){
    int n;
    cin>>n;
    // cout<<staircase(n)<<endl;
    cout<<staircase(n)<<endl;
}
#include<iostream>
using namespace std;

int fib(int n){
    if (n<= 1)
    {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int fib_DP(int n){
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i < n+1; i++)
    {
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[n];
}


int fib_helper(int n, int ans[]){
    if (n<=1)
    {
        return n;
    }

    //check if o/p already exist
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int a = fib_helper(n-1,ans);
    int b = fib_helper(n-2,ans);
    ans[n] = a +b;// save for future
    return ans[n];


}

int fib_Memoization(int n){
    int *ans = new int[n+1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return fib_helper(n,ans);
}

int main(){
    int n;
    cin>>n;
    cout<<fib_DP(n)<<endl;
    cout<<fib_Memoization(n)<<endl;
    cout<<fib(n)<<endl;
}
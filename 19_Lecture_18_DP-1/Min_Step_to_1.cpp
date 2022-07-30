#include<iostream>
#include<climits>
using namespace std;


//Brute-force Recursive solution
// int countMinStepsToOne(int n){
//     if (n == 1)
//     {
//         return 0;
//     }
//     int x = INT_MAX,y = INT_MAX,z = INT_MAX;
//     z = countMinStepsToOne(n-1);
//     if (n % 3 == 0)
//     {
//         x = countMinStepsToOne(n/3);
//     }
//     if (n%2 == 0)
//     {
//         y = countMinStepsToOne(n/2);
//     }
//     int smallAns = min(x, min(y,z));
//     return 1 + smallAns;


//     //very bad assumption
//     // if (n%3 == 0)
//     // {
//     //     return 1 + countMinStepsToOne(n/3);
//     // }
//     // else if (n%2 == 0)
//     // {
//     //     return 1 + countMinStepsToOne(n/2);
//     // }
//     // else return 1+countMinStepsToOne(n-1);
// }


//Memoization Approach
int countMinStepsToOne_Helper(int n, int ans[]){
    if (n == 1)
    {
        return 0;
    }
    
    //check whether o/p already present
    if (ans[n] != -1)
    {
        return ans[n];
    }
    
    int res = countMinStepsToOne_Helper(n-1,ans);
    if (n%2 == 0)
    {
        int r = countMinStepsToOne_Helper(n/2,ans);
        res = min(res,r);
    }
    if (n%3 == 0)
    {
        int r = countMinStepsToOne_Helper(n/3,ans);
        res = min(res,r);
    }
    
    ans[n] = 1 + res;
    return ans[n];
    // return 1 + res;
}


// int countMinStepsToOne(int n){
//     int *ans = new int[n+1];
//     for (int i = 0; i <= n; i++)
//     {
//         ans[i] = -1;
//     }
//     return countMinStepsToOne_Helper(n, ans);
// }
////////////////////


//Dynamic-Programming(DP) Approach (iterative approach)
int countMinStepsToOne(int n){
    int *ans = new int[n+1];
    //smallest known output
    ans[0] = -1;
    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        ans[i] = 1 + ans[i-1];
        if (i % 2 == 0)
        {
            int r = 1 + ans[i/2];
            ans[i] = min(ans[i],r);
        }
        if (i % 3 == 0)
        {
            int r = 1 + ans[i/3];
            ans[i] = min(r,ans[i]);
        }
        


        // if (i%2 == 0)
        // {
        //     ans[i] = 1 + ans[i/2];
        // }
        // else if (i % 3 == 0)
        // {
        //     ans[i] = 1 + ans[i/3];
        // }
        // else 
        //     ans[i] = 1 + ans[i-1];
    }
    for (int i = 0; i <= n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return ans[n];
}


int main(){
    int n;
    cin>>n;
    cout<<countMinStepsToOne(n)<<endl;
}
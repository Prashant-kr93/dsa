#include<iostream>
#include<string>
using namespace std;

//Brute-force(recursive solution)
int lcs(string s, string t){
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    if (s[0] == t[0])
    {
        return 1 + lcs(s.substr(1),t.substr(1));
    }
    
    int a = lcs(s,t.substr(1));
    int b = lcs(s.substr(1),t);
    int c = lcs(s.substr(1), t.substr(1));
    int ans = max(a,max(b,c));
    return ans;
}

//Memoization(top-down) approach

int lcs_helper(string s, string t, int **ans){
    int m = s.size(), n = t.size();
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    
    //check whether o/p is already present or not
    if (ans[m][n] != -1)
    {
        return ans[m][n];
    }

    //recursive call
    int res;
    if (s[0] == t[0])
    {
        res = 1 + lcs_helper(s.substr(1), t.substr(1),ans);
    }
    else{
        int a = lcs_helper(s,t.substr(1), ans);
        int b = lcs_helper(s.substr(1), t, ans);
        int c = lcs_helper(s.substr(1), t.substr(1), ans);
        res = max(a,max(b,c));
    }

    //save for future 
    ans[m][n] = res;
    
    return ans[m][n];
}


int lcs_mem(string s, string t){
    int m = s.size(), n = t.size();
    int** ans = new int*[s.size() + 1];
    for (int i = 0; i < m+1; i++)
    {
        ans[i] = new int[n+1];
        for (int j = 0; j < n + 1; j++)
        {
            ans[i][j] = -1;
        }
        
    }
    return lcs_helper(s,t, ans);
}

//Dynamic Programming (bottom-up) approach
int lcs_DP(string s, string t){
    int m = s.size(),n = t.size();
    int **ans = new int*[m+1];
    for (int i = 0; i < m+1; i++)
    {
        ans[i] = new int[n+1];
    }
    //first fill first row
    for (int j = 0; j < n+1; j++)
    {
        ans[0][j] = 0;
    }
    //then fill first column
    for (int i = 0; i < m+1; i++)
    {
        ans[i][0] = 0;
    }

    //now fill remaining cells
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (s[m-i] == t[n-j])
            {
                ans[i][j] = 1 + ans[i-1][j-1];
            }
            else{
                ans[i][j] = max(ans[i-1][j], max(ans[i][j-1], ans[i-1][j-1]));
            }
        }
        
    }
    return ans[m][n];
    
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<lcs(s,t)<<endl;
    cout<<lcs_mem(s,t)<<endl;
    cout<<lcs_DP(s,t)<<endl;
}
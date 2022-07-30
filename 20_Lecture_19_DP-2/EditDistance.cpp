/*
You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.
 Input format :
The first line of input contains the string S of length M.

The second line of the input contains the String T of length N.
Output format :
Print the minimum 'Edit Distance' between the strings.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation to the Sample Input 1 :
 In 2 operations we can make string T to look like string S.
First, insert character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 

Hence, the minimum distance.
Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9
*/


#include<iostream>
using namespace std;


//Brute-Force recursive approach
int editDistance(string s, string t){
    //base case
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size(), t.size());//anyone have size zero then we have to make both string same 
                                      // so that total operation required is length of string whose size is not zero.
    }

    if (s[0] == t[0])
    {
        return editDistance(s.substr(1),t.substr(1));
    }
    else{
        //insert
        int a = 1 + editDistance(s.substr(1),t);//means first char of s match with 1st char of t
        //delete
        int b = 1 + editDistance(s,t.substr(1));
        //replace
        int c = 1 + editDistance(s.substr(1),t.substr(1));
        return min(a,min(b,c));
    }
}

//Memoization approach
int editDistance_Helper(string s, string t, int **ans){
    int m = s.size(), n = t.size();
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size(), t.size());
    }
    
    //check if ans already present
    if (ans[m][n] != -1)
    {
        return ans[m][n];
    }

    //calculate
    int res;
    if (s[0] == t[0])
    {
        res = editDistance_Helper(s.substr(1),t.substr(1),ans);
    }
    else{
        //insert
        int x = 1 + editDistance_Helper(s.substr(1),t,ans);
        //delete
        int y = 1 + editDistance_Helper(s,t.substr(1),ans);
        //replace
        int z = 1 + editDistance_Helper(s.substr(1),t.substr(1),ans);
        res = min(x,min(y,z));
    }
    
    ans[m][n] = res;
    return ans[m][n];
}


int editDistance_Mem(string s, string t){
    int m = s.size();
    int n = t.size();
    int **ans = new int*[m+1];
    for (int i = 0; i < m+1; i++)
    {
        ans[i] = new int[n+1];
        for (int j = 0; j < n+1; j++)
        {
            ans[i][j] = -1;
        }
        
    }
    return editDistance_Helper(s,t,ans);
}

//DP-Approach(bottom-up)
int editDistance_DP(string s, string t){
    int m = s.size(), n = t.size();
    int **ans = new int*[m+1];
    for (int i = 0; i < m+1; i++)
    {
        ans[i] = new int[n+1];
    }
    //fill first row
    for (int j = 0; j < n+1; j++)
    {
        ans[0][j] = j;
    }
    //fill first column
    for (int i = 0; i < m+1; i++)
    {
        ans[i][0] = i;
    }
    
    //fill remaining cells
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (s[m-i] == t[n-j])
            {
                ans[i][j] = ans[i-1][j-1];
            }
            else{
                int x = ans[i-1][j];//insert
                int y = ans[i][j-1];//delete
                int z = ans[i-1][j-1];//replace
                ans[i][j] = 1 + min(x,min(y,z));// add 1 b'coz one operation more after call previous all situation and min of them

            }
        }
        
    }
    // for (int i = 0; i < m+1; i++)
    // {
    //     for (int j = 0; j < n+1; j++)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return ans[m][n];
}


int main(){
    string s,t;
    cin>>s>>t;
    cout<<editDistance(s,t)<<endl;
    cout<<editDistance_Mem(s,t)<<endl;
    cout<<editDistance_DP(s,t)<<endl;
}
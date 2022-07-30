/*
Given an array of length N and an integer x, you need to find and 
return the last index of integer x present in the array. 
Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
You should start traversing your array from 0, not from (N - 1).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
last index or -1
Constraints :
1 <= N <= 10^3
Sample Input :
4
9 8 10 8
8
Sample Output :
3
*/

#include<iostream>
using namespace std;

int lastIndex(int arr[],int n, int x)
{
    if (n<=0)
    {
        return -1;
    }
    int ans = lastIndex(arr+1,n-1,x);//bus apne ko recursive
                                    //call karna wo kaise karega uske bare m nhi sochna hai
                                    //apne ko wo recursion ka work hai wo hume ans lakar dega
    
    if (ans == -1)
    {
        if (arr[0]==x)
        {
            return 0;
        }
        else{
            return -1;
        }
    
    }
    
    return 1+ans;
    

    //traversing from 0th index
    // if (n <= 0)
    // {
    //     return -1;
    // }
    // if (arr[0] == x)
    // {
    //     int ans = lastIndex(arr+1,n-1,x);
    //     return 1 + ans;
    // }
    // int smallAns = lastIndex(arr+1,n-1,x);
    // if (smallAns == -1)
    // {
    //     return -1;
    // }
    // else{
    //     return 1 + smallAns;
    // }
    


    // traversing from (n-1) index
    // if (n<=0)
    // {
    //     return -1;
    // }
    
    // if (arr[n-1]==x)
    // {
    //     return (n-1);
    // }
    // int ans = lastIndex(arr,n-1,x);
    // return ans;
    
    
}

int main(){
    int n;
    cin>>n;
    int * arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<lastIndex(arr,n,x)<<endl;
}
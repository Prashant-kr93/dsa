#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int arr[],int si, int ei){
    if(si > ei) return 0;
    int smallans = longestSubsequence(arr+2,si+2,ei);
    if(si + 1 <= ei && arr[si] < arr[si+1]){
        if (si + 2 <= ei && arr[si+1] > arr[si+2])
        {
            return 2 + smallans;
        }
        
        return smallans;
    }
    else if (si + 1 <= ei && si + 2 <= ei && arr[si + 1] > arr[si + 2])
    {
        return 1 + smallans;
    }
    else
        return smallans;
}


int longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    int *arr = new int[n+1];
    // int ans = 0;
    // bool fla
    for(int i = 0;i<n;i++){
        arr[i]  = A[i];
    }
    // if(n == 0) return 0;
    // int smallans = longestSubsequenceLength(A+1);
    // if(A[0] < A[1]){
    //     return 1 + smallans;
    // }
    int ans = longestSubsequence(arr,0,n-1);
    delete[] arr;
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        A.push_back(x);
    }
    cout<<longestSubsequenceLength(A);
}
#include<iostream>
using namespace std;

bool is_sorted(int a[], int n){
    if (n==0|| n== 1)
    {
        return true;
    }
    if (a[0]>a[1])
    {
        return false;
    }
    return is_sorted(a+1,n-1);
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    bool ans = is_sorted(arr,n);
    cout<<ans<<endl;
    delete[] arr;
    
}
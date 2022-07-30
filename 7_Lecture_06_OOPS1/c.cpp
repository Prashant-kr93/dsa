#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool permutation(ll *arr, ll n)
{
    ll check[n+1]= {0};
    for (ll i = 0; i < n; i++)
    {
        while (arr[i]>=1)
        {
            if ((arr[i]>=1 && arr[i]<=n) && check[arr[i]] == 0)
            {
                check[arr[i]] = 1;
                break;
            }
            
            arr[i] /=2;   
        }
        
    }
    // for (ll i = 0; i <= n; i++)
    // {
    //     cout<<check[i]<<" ";
    // }
    
    for (ll i = 1; i <=n; i++)
    {
        if (check[i] == 0)
        {
            return false;
        }
        
    }
    return true;

}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll * arr = new ll[n];
        for (ll i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        if (permutation(arr,n))
        {
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;

        delete[] arr;
    }
    return 0;
}
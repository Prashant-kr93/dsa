#include<iostream>
using namespace std;

int countMinStepsToOne(int n){
    int *ans = new int[n+1];
    ans[0] = -1;
    ans[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = 1 + ans[i-1];
        if (i%2 == 0)
        {
            ans[i] = min(ans[i],1 + ans[i/2]);
        }
        if (i % 3 == 0)
        {
            ans[i] = min(ans[i], 1 + ans[i/3]);
        }
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
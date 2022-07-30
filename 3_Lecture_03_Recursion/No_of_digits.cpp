/*
Given the code to find out and return the number of digits 
present in a number recursively. But it contains few bugs, 
that you need to rectify such that all the test cases should pass.
*/

#include<bits/stdc++.h>
using namespace std;

int count(int n){
    if (n<10)
    {
        return 1;
    }
    int smallAns = count(n/10);
    return smallAns+1;
}

// int count(int n){
//     if (n == 0)
//     {
//         return 0;
//     }
//     int smallans = count(n/10);
//     return 1 + smallans;
// }

int main(){
    int n;
    cin>>n;
    cout<<count(n)<<endl;
}


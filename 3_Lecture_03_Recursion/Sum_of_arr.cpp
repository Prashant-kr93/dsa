/*
Given an array of length N, you need to find and return the sum of all elements of the array.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Sum
*/

#include<iostream>
using namespace std;

// int sum(int *arr, int n){
//     if (n == 0)
//     {
//         return 0;
//     }
//     if (n==1)
//     {
//         return arr[n-1];
//     }
//     return arr[0] + sum(arr+1,n-1);
    
// }
/*
For recursion on array firstly we split it into two parts
one for recursive call and one for doing small calculation.
For spliting array ther are many way to split:
1. First + remaining element
2. last + 0 to n-2 index element
3. Split b/w two any part and call recursion on both and do calculation (like here sum)
*/

int sum_of_arr(int arr[], int n){
    if (n == 0)
    {
        return 0;
    }
    return arr[0] + sum_of_arr(arr+1,n-1);
    
}
// int sum(int *arr, int n){
//     if (n ==0)
//     {
//         return 0;
//     }
//     int smallAns1 = sum(arr,(n+1)/2);
//     int smallAns2 = sum(arr+n/2,n/2);// this will not work because arr is pointer so if we call again then it goes above than our expectation.

//     return smallAns1 + smallAns2;
// }

int main(){
    int n;
    cin>>n;
    int * arr = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    // cout<<sum(arr,n)<<endl;
    cout<<sum_of_arr(arr,n)<<endl;
}
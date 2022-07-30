/*
Given an array of length N and an integer x, you need to find 
if x is present in the array or not. Return true or false.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
'true' or 'false'
*/

#include<iostream>
using namespace std;

bool checkNumber(int arr[], int n, int x){
    if (arr[0] == x)
    {
        return true;
    }
    if (n<=0)
    {
        return false;
    }
    
    return checkNumber(arr+1,n-1,x);
}

int main(){
    int n;
    cin>>n;
    int *arr = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
    int x;
    cin>>x;
    if (checkNumber(arr,n,x))
    {
        cout<<"true"<<endl;
    }
    else
        cout<<"false"<<endl;
}

bool checkNumber(int arr[], int n, int x){
    if (n == 0)
    {
        return false;
    }
    
    
}
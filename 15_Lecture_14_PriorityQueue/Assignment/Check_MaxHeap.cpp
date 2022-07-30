/*
Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains true if it represents max-heap and false if it is not a max-heap.
Constraints:
1 <= N <= 10^5
1 <= Ai <= 10^5
Time Limit: 1 sec
Sample Input 1:
8
42 20 18 6 14 11 9 4
Sample Output 1:
true
*/

#include<iostream>
using namespace std;

//approach-I
bool isMaxHeap(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        int lci = 2*i + 1;
        int rci = 2*i + 2;
        if (lci<n && arr[lci]>arr[i])
        {
            return false;
        }
        if (rci<n && arr[rci]>arr[i])
        {
            return false;
        }
        
    }
    return true;
}
//approach-II
bool isMaxHeap2(int *arr, int n){
    for (int childIndex = 1; childIndex < n; childIndex++)
    {
        int parentIndex = (childIndex - 1)/2;
        if (arr[parentIndex] < arr[childIndex])
        {
            return false;
        }
        
    }
    return true;
    
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<(isMaxHeap(arr,n) ? "true\n":"false\n");
    cout<<(isMaxHeap2(arr,n) ? "true\n" : "false\n");

}
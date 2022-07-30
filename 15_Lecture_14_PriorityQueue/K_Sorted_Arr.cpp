#include<iostream>
using namespace std;
#include<queue>

//time complexity approximately O(n*logk) ~= O(n) if n>>>k;
void kSortedArray(int input[], int n, int k){
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }
    int j = 0;
    for (int i = k; i < n; i++)
    {
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }// till now n-k element only sorted 

    while (!pq.empty())
    {
        input[j] = pq.top();
        pq.pop();
        j++;
    }
    
    
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    kSortedArray(arr,n,k);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    delete[] arr;
}
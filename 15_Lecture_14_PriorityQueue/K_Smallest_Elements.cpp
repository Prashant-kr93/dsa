#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#include<algorithm>

vector<int> kSmallest(int arr[], int n, int k){
    priority_queue<int> maxHeap;
    for (int i = 0; i < k; i++)
    {
        maxHeap.push(arr[i]);
    }
    
    for (int i = k; i < n; i++)
    {
        if (arr[i]< maxHeap.top())
        {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
        
    }
    vector<int> output;
    while (! maxHeap.empty())
    {
        output.push_back(maxHeap.top());
        maxHeap.pop();
    }
    
    return output;
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
    vector<int> output = kSmallest(arr,n,k);
    sort(output.begin(),output.end());
    for (int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
    
    delete[] arr;
}
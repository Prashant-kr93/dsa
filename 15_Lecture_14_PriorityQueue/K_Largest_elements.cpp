#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> kLargest(int input[], int n, int k){
    priority_queue<int, vector<int>, greater<int> > minHeap;
    for (int i = 0; i < k; i++)
    {
        minHeap.push(input[i]);
    }
    for (int i = k; i < n; i++)
    {
        int min = minHeap.top();
        if (input[i] > min)
        {
            minHeap.pop();
            minHeap.push(input[i]);
        }
        
    }
    vector<int> output;
    while (! minHeap.empty())
    {
        output.push_back(minHeap.top());
        minHeap.pop();
    }
    return output;
    
}

int main(){
    int n;
    cin>>n;
    int*arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<int> output = kLargest(arr,n,k);
    for (int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
    
    delete[] arr;
}
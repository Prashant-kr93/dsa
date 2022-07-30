#include<iostream>
using namespace std;

int partition(int *arr, int si,int ei){
    
    int pivot = arr[si];
    int pi = si;
    for (int i =si + 1; i <= ei; i++)
    {
        if (arr[i] < pivot)
        {
            pi++;
        }
           
    }
    //swaping with pivot element
    arr[si] = arr[pi];
    arr[pi] = pivot;

    int i = si,j = ei;
    while (i<pi && j>pi)
    {
        if (arr[i]>pivot && arr[j]<=pivot)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++,j--;
        }
        else if (arr[i]<pivot)
        {
            i++;
        }
        else if(arr[j]>=pivot){
            j--;
        }
    }
    return pi;

    
}

void quickSort(int *arr,int si, int ei){
    if (si>=ei)
    {
        return;
    }
    int pi= partition(arr,si,ei);
    quickSort(arr,si,pi-1);
    quickSort(arr,pi+1,ei);
}


void quicksort(int *arr, int n){
    int si = 0, ei= n-1;
    quickSort(arr,si,ei);
}


int findDuplicate(int *arr, int n){
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] == arr[i+1])
        {
            return arr[i];
        }
        
    }
    
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int * arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        quicksort(arr,n);
        cout<<findDuplicate(arr,n)<<endl;

        // cout<<arr[0]<<endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        
    }
    
}
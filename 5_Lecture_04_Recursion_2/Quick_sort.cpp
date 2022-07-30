#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *b;
    *b  = *a;
    *a = temp;
}




int partition(int arr[],int si, int ei){
    int pivot = arr[si];
    int pi = si;
    for (int i = si+1; i <= ei; i++)
    {
        if (arr[i]<pivot) // means here we want left side contains strictly less than pivot and in right side contain greater or equal to pivot.
        {
            pi++;
        }
        
    }
    arr[si] = arr[pi];
    arr[pi] = pivot;
    
    //now arrange/swaping of no. around pivot elemnet
    //Ensure left half contains less than pivot and right half contains greater or equal to pivot.
    int i = si, j = ei;
    while (i<pi && j>pi)
    {
        // all element left of pivot are strictly less than pivot so 
        if (arr[i]>=pivot && arr[j]<pivot)
        {
            swap(arr[i],arr[j]);
            i++,j--;
        }
        else if (arr[i]<pivot) // v.v.i step here not equality sign 
        {
            i++;
        }
        else if(arr[j]>=pivot)// v.v.i step for equality sign means if equal then leave that no. for same index and go for further.
        {
            j--;
        }
        
        
    }
    return pi;

}

void quicksort(int *arr,int si,int ei){
    if (si>=ei)
    {
        return;
    }
    int pi = partition(arr,si,ei);
    quicksort(arr,si,pi-1);
    quicksort(arr,pi+1,ei);
}

void QuickSort(int *input, int n){
    int si = 0, ei = n-1;
    quicksort(input,si,ei);
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    QuickSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    delete[] arr;
}
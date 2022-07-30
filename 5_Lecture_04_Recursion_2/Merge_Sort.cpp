#include<iostream>
using namespace std;

void merge_2_sorted(int *arr,int si,int ei){
    int n = ei-si+1;
    int mi = (si+ei)/2;
    int output[n];
    int i = si, j = mi+1;
    int k = 0;
    while (i<=mi && j<=ei)
    {
        if (arr[i]<arr[j])
        {
            output[k] = arr[i];
            i++,k++;
        }
        else{
            output[k] = arr[j];
            j++,k++;
        }
    }
    while (i<=mi)
    {
        output[k] = arr[i];
        k++,i++;
    }
    while (j<=ei)
    {
        output[k] = arr[j];
        k++;j++;
    }
    

    //very very curicial step 
    //here we sending arr from start index so must we have to start from si of arr to copy elemnt of output array
    int m = 0;
    for (int i = si; i <=ei; i++)
    {
        arr[i] = output[m];
        m++;
    }
    
}


void merge_Sort(int *input, int si, int ei){
    if (si>=ei)
    {
        return;
    }
    int mi = (si+ei)/2;
    merge_Sort(input,si,mi);
    merge_Sort(input,mi+1,ei);
    merge_2_sorted(input,si,ei);
}

void mergeSort(int *input,int size){
    int si = 0,ei = size -1;
    merge_Sort(input,si,ei);
}

int main(){
    int length;
    cin>>length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
    {
        cin>>input[i];
    }
    mergeSort(input,length);
    for (int i = 0;i<length; i++)
        cout<<input[i]<<" ";
    delete[] input;
}

// Merge Sort

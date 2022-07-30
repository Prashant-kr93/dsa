/*
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2
*/

#include <iostream>
using namespace std;

void buildHeap(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex != 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[parentIndex] > arr[childIndex])
            {
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;
            }
            childIndex = parentIndex;
        }
    }
}

void removeMin(int *arr, int n)
{
    if (n == 0)
    {
        return;
    }
    while (n > 1)
    {
        int temp = arr[n - 1];
        arr[n - 1] = arr[0];
        arr[0] = temp;
        n -= 1;
        // Heapify
        int parentIndex = 0;
        while (parentIndex < n)
        {
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;
            int minIndex = -1;

            if (leftChildIndex < n && rightChildIndex < n)
            {
                if (arr[leftChildIndex] < arr[rightChildIndex])
                {
                    minIndex = leftChildIndex;
                }
                else
                {
                    minIndex = rightChildIndex;
                }
            }
            else if (leftChildIndex < n)
            {
                minIndex = leftChildIndex;
            }
            else if (rightChildIndex < n)
            {
                minIndex = rightChildIndex;
            }

            if (minIndex != -1 && arr[parentIndex] > arr[minIndex])
            {
                int temp = arr[minIndex];
                arr[minIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
                parentIndex = minIndex;
            }
            else
                break;

            // leftChildIndex = 2 * parentIndex + 1;
            // rightChildIndex = 2 * parentIndex + 2;
        }
    }
}

void heapSort(int *arr, int n)
{
    buildHeap(arr, n);
    removeMin(arr,n);
    // for (int i = 0; i < n; i++)
    // {
    //     removeMin(arr, n - i);
    // }
}

int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    heapSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
}
#include<bits/stdc++.h>
using namespace std;

bool path(int**arr, int row, int n){
    if (row >= n)
    {
        
        return true;
    }
    
}


void N_Queen(int **arr, int n){

}

int main(){
    int n;
    cin>>n;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
        
    }

    
    return 0;
}
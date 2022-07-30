/*
Given an integer N, count and return the number of zeros 
that are present in the given integer using recursion.
Input Format :
Integer N

Output Format :
Number of zeros in N

Constraints :
0 <= N <= 10^9

Sample Input 1 :
10204

Sample Output 1 :
2

Sample Input 2 :
708000

Sample Output 2 :
4



*/

#include<iostream>
#include<strings.h>
using namespace std;

int countZeros(int n) 
{
    string st= to_string(n);
    int count = 0;
    for (int i = 0; st[i] != '\0'; i++)
    {
        if (st[i]=='0')
        {
            count++;
        }
        
    }
    return count;
    

    // int count = 0;
    // if (n%)
    // {
    //     /* code */
    // }
    
    // if (n==0)
    // {
    //     return 0;
    // }
    // int ans = countZeros(n/10);
    // if (n%10 == 0)
    // {
    //     return 1;
    // }
    
    
    // return 1+ans;

}

int main(){
    int n;
    cin>>n;
    cout<<countZeros(n)<<endl;
}
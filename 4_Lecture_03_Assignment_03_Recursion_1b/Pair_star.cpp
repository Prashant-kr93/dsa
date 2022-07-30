/*
// Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S
Output format :
Modified string
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a
*/


#include<iostream>
using namespace std;

int len(char input[]){
    int l = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        l++;
    }
    return l;
    
}

void pairstar(char input[], int si){
    // int l = len(input);
    if (input[si] == '\0')
    {
        return;
    }
    pairstar(input,si+1);
    if (input[si] == input[si+1])
    {   
        int l = len(input);
        for (int i = si+1; i < si + l; i++)
        {
            input[i+1] = input[i];
        }
        input[si+1] = '*';
        pairstar(input,si+2);
    }
    // pairstar(input+1,si+1);
}

void pairStar(char input[]){
    int l = len(input);
    // pairstar(input,0);
    if (input[0] == '\0')
    {
        return;
    }
    if (input[0] == input[1])
    {
        int l = len(input);
        input[l+1] = '\0';
        for (int i = l-1; i >=1; i--)
        {
            input[i+1] = input[i];
        }
        input[1] = '*';
        pairStar(input+2);
    }
    pairStar(input+1);
    
    // cout<<l<<endl;
}

int main(){
    char input[100];
    cin.getline(input,100);
    pairStar(input);
    cout<<input<<endl;
}
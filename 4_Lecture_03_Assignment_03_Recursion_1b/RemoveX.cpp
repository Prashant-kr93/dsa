/*
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:

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

void removeX(char input[]){
    int l = len(input);
    if (l == 0)
    {
        return;
    }
    if (input[0] == 'x')
    {
        for (int i = 0; i < len(input); i++)
        {
            input[i] = input[i+1];
        }
        removeX(input);
    }
    removeX(input+1);

}

int main(){
    char *input = new char[100];
    cin.getline(input,100);
    removeX(input);
    cout<<input<<endl;
    delete[] input;
}
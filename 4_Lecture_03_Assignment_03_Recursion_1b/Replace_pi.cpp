/*
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
Constraints:-
1<=|S|<=50
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

void replacePi(char input[]){
    int l = len(input);
    if (l == 0)
    {
        return;
    }
    if (input[0] == 'p' && input[1] == 'i')
    {
        int l = len(input);
        for (int i = l-1; i>1; i--)
        {
            input[i+2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        replacePi(input+4);
    }
    // else{
    //     replacePi(input+1);
    // }
    replacePi(input + 1);
}

int main(){
    char input[10000];
    cin.getline(input,10000);
    // cout<<len(input);
    replacePi(input);
    cout<<input<<endl;
}
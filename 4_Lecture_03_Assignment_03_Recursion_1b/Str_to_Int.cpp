/*
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 <= |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
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

int helper(char input[], int si, int ei){
    if (si > ei)
    {
        return 0;
    }
    int smallans = helper(input,si,ei-1);
    int c = int(input[ei]) - 48;
    return (smallans*10) + c;
    
}

int stringToNumber(char input[]){
    int l = len(input);
    helper(input,0,l-1);
    
}

int main(){
    char input[50];
    cin>>input;
    cout<<stringToNumber(input)<<endl;
}
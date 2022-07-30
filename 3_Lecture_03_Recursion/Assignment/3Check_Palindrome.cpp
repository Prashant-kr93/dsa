/*
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false

bool checkPalindrome(char input[]) {
    // Write your code here

}
*/

#include <iostream>
// #include "solution.h
using namespace std;

bool checkPalindrome(char str[]) {
    // Write your code here
    
    int h =0;
    for(int i = 0;str[i]!='\0';i++ )
    {
        h++;
    }
    
    cout<<h;
    h--;
    int l = 0;
    // int h = strlen(str) - 1;
 
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            // printf("%s is not a palindrome\n", str);
            return false;
        }
    }
    // printf("%s is a palindrome\n", str);
    return true;
// }

}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

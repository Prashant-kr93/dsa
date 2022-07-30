#include<iostream>
using namespace std;

string getstring(int num){
    string m[] = {"","","abc","def","ghi","jkl",
    "mno","pqrs","tuv","wxyz"};
    return m[num];
}

void printKeypad(int n,string output){
    if (n == 0)
    {
        cout<<output<<endl;
        return;
    }
    int smallnum = n/10;
    int last_num = n%10;
    string options = getstring(last_num);
    for (int i = 0; i < options.size(); i++)
    {
        printKeypad(smallnum,options[i] +output);
    }
    
    
}

void printkeypad(int num){
    printKeypad(num,"");
}

int main(){
    int n;
    cin>>n;
    cout<<getstring(n);
    printkeypad(n);
}
#include<iostream>
using namespace std;

int main(){
    int a[5] = {1,2,3};
    int *ptr = a;
    cout<<a<<endl;
    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    cout<<*ptr<<endl;
    cout<<*(ptr + 1)<<endl;

}

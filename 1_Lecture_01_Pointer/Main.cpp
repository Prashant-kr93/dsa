// #include<iostream>
// using namespace std;

// int main(){
//     int a = 10,b;
//     int *p = &a;
//     int* *q = &p;
//     b = ++(**q) + 4;
//     cout<<a<<' '<<b<<endl;
//     b = ((**q)++) + 4;
//     cout<<a << " "<<b;
// }
#include<iostream>
using namespace std;
void swap (char *x, char *y) 
{
  char *t = x;
  x = y;
  y = t;
}

int main()
{
   char *x = "geeksquiz";
   char *y = "peeksforgeeks";
   char *t;
   swap(x, y);
   cout<<x << " "<<y;
   t = x;
   x = y;
   y = t; 
   cout<<" "<<x<< " "<<y;
   return 0;
}
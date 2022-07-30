/*
Given is the code to print numbers from 1 to n in increasing order recursively. But it contains few bugs that you need to rectify such that all the test cases pass.
Input Format :
Integer n
Output Format :
Numbers from 1 to n (separated by space)

*/
#include <iostream>
using namespace std;

// void print(int n)
// {
//     if (n == 1)
//     {
//         cout << n << " ";
//     }
//     else
//     {
//         // cout << n << " ";
//         print(n-1);
//         cout<<n<<" ";
//     }
// }

// void print(int n)
// {
//     if (n == 1)
//     {
//         cout<<n<<" ";
//         return;
//     }
//     // cout<<n<<" ";
//     print(n-1);
//     cout<<n<<" ";
    
// }

/*
for printing 1 to n if we print 1 to n-1 then print n
then our work done so for print 1 to n-1 we do it by recursively
and then print last no. n*/

void print(int n){
    if (n == 0)
    {
        return;
    }
    print(n-1);
    cout<<n<<" ";
}

int main()
{
    int n;
    cin >> n;
    print(n);
}


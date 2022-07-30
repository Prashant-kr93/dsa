#include<iostream>
using namespace std;

int keypad(int n, string output[]){
    if (n <=1)
    {
        return 1;
        output[0] = "";
    }
    int smallans = keypad(n/10,output);
    int check = n%10;
    if (check == 2)
    {
        string s = "abc";
        // int i = 0,j =0,k=0;
        // int ans = smallans*s.size();
        // while (k<ans)
        // {
        //     while (j<smallans)
        //     {
        //         while (i<s.size())
        //         {
        //             output[k] = output[j]+ s[i];
        //             k++;
        //             i++;
        //         }
        //         j++;
        //     }
            
        // }
        
        // int k =0;
        // for (int i = 0; i < smallans; i++)
        // {
        //     for (int j = 0; j < s.size(); j++)
        //     {
                
        //         output[k] = output[k] + s[j];
        //         k++;
        //     }
                        
        // }


        string map[smallans];
        for (int i = 0; i < smallans; i++)
        {
            map[i] = output[i];
        }
        int k = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < smallans; j++)
            {
                output[k] = map[j] + s[i];
                k++;
            }
            
        }
        return smallans*s.size();
    }
    if (check == 3)
    {
        string s = "def";
        // int i = 0,j =0,k=0;
        // int ans = smallans*s.size();
        // while (k<ans)
        // {
        //     while (j<smallans)
        //     {
        //         while (i<s.size())
        //         {
        //             output[k] = output[j]+ s[i];
        //             k++;
        //             i++;
        //         }
        //         j++;
        //     }
            
        // }
        string map[smallans];
        for (int i = 0; i < smallans; i++)
        {
            map[i] = output[i];
        }
        int k = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < smallans; j++)
            {
                output[k] = map[j] + s[i];
                k++;
            }
            
        }
        
        
        return smallans*s.size();
    }
    if (check == 4)
    {
        string s = "ghi";
        // for (int i = 0; i < s.size(); i++)
        // {
        //     for (int j = 0; j < smallans; j++)
        //     {
        //         output[j] += s[i];
        //     }
                        
        // }
        string map[smallans];
        for (int i = 0; i < smallans; i++)
        {
            map[i] = output[i];
        }
        int k = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < smallans; j++)
            {
                output[k] = map[j] + s[i];
                k++;
            }
            
        }
        return smallans*s.size();
    }
    if (check == 5)
    {
        string s = "jkl";
        // for (int i = 0; i < s.size(); i++)
        // {
        //     for (int j = 0; j < smallans; j++)
        //     {
        //         output[j] += s[i];
        //     }
                        
        // }
        string map[smallans];
        for (int i = 0; i < smallans; i++)
        {
            map[i] = output[i];
        }
        int k = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < smallans; j++)
            {
                output[k] = map[j] + s[i];
                k++;
            }
            
        }
        return smallans*s.size();
    }
    if (check == 6)
    {
        string s = "mno";
        // for (int i = 0; i < s.size(); i++)
        // {
        //     for (int j = 0; j < smallans; j++)
        //     {
        //         output[j] += s[i];
        //     }
                        
        // }
        string map[smallans];
        for (int i = 0; i < smallans; i++)
        {
            map[i] = output[i];
        }
        int k = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < smallans; j++)
            {
                output[k] = map[j] + s[i];
                k++;
            }
            
        }
        return smallans*s.size();
    }
    if (check == 7)
    {
        string s = "pqrs";
        // for (int i = 0; i < s.size(); i++)
        // {
        //     for (int j = 0; j < smallans; j++)
        //     {
        //         output[j] += s[i];
        //     }
                        
        // }
        string map[smallans];
        for (int i = 0; i < smallans; i++)
        {
            map[i] = output[i];
        }
        int k = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < smallans; j++)
            {
                output[k] = map[j] + s[i];
                k++;
            }
            
        }
        return smallans*s.size();
    }
    if (check == 8)
    {
        string s = "tuv";
        // for (int i = 0; i < s.size(); i++)
        // {
        //     for (int j = 0; j < smallans; j++)
        //     {
        //         output[j] += s[i];
        //     }
                        
        // }
        string map[smallans];
        for (int i = 0; i < smallans; i++)
        {
            map[i] = output[i];
        }
        int k = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < smallans; j++)
            {
                output[k] = map[j] + s[i];
                k++;
            }
            
        }
        return smallans*s.size();
    }
    if (check == 9)
    {
        string s = "wxyz";
        // for (int i = 0; i < s.size(); i++)
        // {
        //     for (int j = 0; j < smallans; j++)
        //     {
        //         output[j] += s[i];
        //     }
                        
        // }
        string map[smallans];
        for (int i = 0; i < smallans; i++)
        {
            map[i] = output[i];
        }
        int k = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < smallans; j++)
            {
                output[k] = map[j] + s[i];
                k++;
            }
            
        }
        return smallans*s.size();
    }
}

int main(){
    int n;
    cin>>n;
    string output[10000];
    int count = keypad(n,output);
    for (int i = 0; i <  count && i<10000; i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}
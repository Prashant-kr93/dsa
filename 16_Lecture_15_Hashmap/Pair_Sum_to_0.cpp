#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int pairSum(int *arr, int n)
{
    // M-I(best approach)
    unordered_map<int,int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int complement = -arr[i];
        if (mp.count(complement) > 0)
        {
            ans += mp[complement];
        }
        mp[arr[i]] ++;
    }
    
    return ans;

    /*
    unordered_map<int, int> ourmap;
    M-II(not completed if faced only 0 as element)
    for (int i = 0; i < n; i++)
    {
        ourmap[arr[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (ourmap[arr[i]] > 0)
        {
            if (ourmap[arr[i]] == n)
            {
                ans += 2 * n;
                ourmap[arr[i]] = 0;
                ourmap[(-1) * arr[i]] = 0;
            }
            else if(ourmap[(-1) * arr[i]] > 0)
            {
                ans += ourmap[arr[i]] * ourmap[(-1) * arr[i]];

                ourmap[arr[i]] = 0;
                ourmap[(-1) * arr[i]] = 0;
                // ourmap[(-1)*arr[i]]--;
            }
        }
    }
    return ans;
    */
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << pairSum(arr, n) << endl;
    delete[] arr;
}